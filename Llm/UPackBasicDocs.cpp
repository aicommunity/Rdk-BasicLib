#include "UPackBasicDocs.h"

#include <algorithm>
#include <cctype>

namespace RDK::LLM {

namespace {

std::string toLowerAscii(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

bool looksLikeBasicDomain(const std::string& text)
{
    const std::string lower = toLowerAscii(text);
    return lower.find("basiclib") != std::string::npos || lower.find("matrixsource") != std::string::npos
           || lower.find("scalarsource") != std::string::npos || lower.find("fileio") != std::string::npos
           || lower.find("umatrix") != std::string::npos || lower.find("unoise") != std::string::npos
           || lower.find("dataset") != std::string::npos || text.find("матриц") != std::string::npos
           || text.find("источник") != std::string::npos;
}

} // namespace

PackMatch UPackBasicDocs::match(const PackTurnSnapshot& snap) const
{
    PackMatch m;
    if(!snap.req || snap.skip_pre_llm_funnel)
        return m;
    if(!looksLikeBasicDomain(snap.req->user_text) && !looksLikeBasicDomain(snap.planning_text))
        return m;
    m.score = 0.55f;
    m.reason = "basic_domain_hint";
    return m;
}

PackHintContribution UPackBasicDocs::hints(const PackTurnSnapshot& snap) const
{
    (void)snap;
    PackHintContribution h;
    h.ephemeral_markdown =
        "## Basic library\n"
        "For MatrixSource / ScalarSource / FileIO / Noise / Statistic questions, prefer "
        "`search_basic_docs` and `list_basic_component_classes` before inventing class names.";
    h.extra_tool_names = {"search_basic_docs", "list_basic_component_classes", "describe_class",
                          "search_project_docs", "search_tools"};
    h.act_or_clarify_recovery_tools = {"search_basic_docs", "list_basic_component_classes",
                                       "search_tools", "spawn_explore_subagent", "ask_user"};
    return h;
}

} // namespace RDK::LLM
