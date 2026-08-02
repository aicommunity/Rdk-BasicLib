#include "RegisterBasicLibLlmTools.h"

#include <filesystem>
#include <memory>

#include "../../../Rdk/LLM/Core/Context/ILLMProjectContextProvider.h"
#include "../../../Rdk/LLM/Core/Context/UDocSearchIndex.h"
#include "../../../Rdk/LLM/Core/Context/ULLMDocOpenPolicy.h"
#include "../../../Rdk/LLM/Core/Domain/URdkDomainAccess.h"
#include "../../../Rdk/LLM/Core/LlmPublicApi.h"
#include "../../../Rdk/LLM/Core/Tools/ULLMToolRegistry.h"
#include "UPackBasicDocs.h"

namespace fs = std::filesystem;

namespace {

RDK::LLM::LLMToolDefinition makeReadDef(const std::string& name, const std::string& desc,
                                        nlohmann::json input)
{
    RDK::LLM::LLMToolDefinition d;
    d.name = name;
    d.kind = RDK::LLM::LLMToolKind::Read;
    d.description = desc;
    d.input_schema = std::move(input);
    d.output_schema = {{"type", "object"}};
    return d;
}

fs::path basicDocsRoot(RDK::LLM::ILLMProjectContextProvider* ctx)
{
    if(!ctx)
        return {};
    return ctx->paths().repository_root / "Libraries" / "Rdk-BasicLib" / "Docs";
}

} // namespace

void RegisterBasicLibLlmTools(RDK::LLM::ULLMToolRegistry& registry,
                              RDK::LLM::ILLMProjectContextProvider* project_context,
                              RDK::LLM::URdkDomainAccess& domain)
{
    registry.registerTool(
        makeReadDef("search_basic_docs",
                    "Search Rdk-BasicLib documentation (MatrixSource, FileIO, Noise, Statistic)",
                    {{"type", "object"},
                     {"required", {"query"}},
                     {"properties",
                      {{"query", {{"type", "string"}}}, {"top_k", {{"type", "integer"}}}}},
                     {"additionalProperties", false}}),
        [project_context](const nlohmann::json& args) -> RDK::LLM::ToolGatewayResult {
            RDK::LLM::ToolGatewayResult r;
            const std::string query = args.at("query").get<std::string>();
            const int top_k = args.value("top_k", 5);
            const fs::path root = basicDocsRoot(project_context);
            std::vector<fs::path> roots;
            if(!root.empty())
                roots.push_back(root);
            auto snippets = RDK::LLM::searchDocsWithIndex(roots, query, top_k);
            r.result["snippets"] = nlohmann::json::array();
            r.result["library"] = "Rdk-BasicLib";
            for(const auto& s : snippets)
            {
                nlohmann::json row = {{"path", s.path},
                                      {"title", s.title},
                                      {"excerpt", s.excerpt},
                                      {"score", s.score}};
                if(project_context)
                    RDK::LLM::enrichSnippetDocUri(row, s.path,
                                                  project_context->paths().repository_root);
                r.result["snippets"].push_back(std::move(row));
            }
            r.ok = true;
            return r;
        });

    registry.registerTool(
        makeReadDef("list_basic_component_classes",
                    "Lists BasicLib / IOLibrary component class names from the live registry",
                    {{"type", "object"}, {"additionalProperties", false}}),
        [&domain](const nlohmann::json& args) -> RDK::LLM::ToolGatewayResult {
            (void)args;
            RDK::LLM::ToolGatewayResult r;
            nlohmann::json out;
            // BasicLib + IOLibrary share Rdk-BasicLib sources; merge both filters.
            nlohmann::json merged = nlohmann::json::array();
            for(const char* lib : {"BasicLib", "IOLibrary"})
            {
                if(!domain.listRegisteredClasses(out, lib).ok())
                    continue;
                for(const auto& item : out.value("classes", nlohmann::json::array()))
                    merged.push_back(item);
            }
            r.result["classes"] = std::move(merged);
            r.result["docs_hint"] = "Libraries/Rdk-BasicLib/Docs/README.md";
            r.result["mutation_hint"] = "Use add_component with class_name from this list.";
            r.ok = true;
            return r;
        });

    if(RDK::LLM::LLMServices::instance().isInitialized())
    {
        RDK::LLM::LLMServices::instance().packs().registerPack(
            std::make_unique<RDK::LLM::UPackBasicDocs>());
    }
}
