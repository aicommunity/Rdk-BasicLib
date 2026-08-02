#ifndef RDK_LLM_PACK_BASIC_DOCS_H
#define RDK_LLM_PACK_BASIC_DOCS_H

#include "../../../Rdk/LLM/Core/Packs/ILLMCapabilityPack.h"

namespace RDK::LLM {

/// Library pack adapter: Rdk-BasicLib docs / class discovery hints.
class UPackBasicDocs : public ILLMCapabilityPack {
public:
    const char* id() const override { return "basic_docs"; }
    PackMatch match(const PackTurnSnapshot& snap) const override;
    PackHintContribution hints(const PackTurnSnapshot& snap) const override;
};

} // namespace RDK::LLM

#endif
