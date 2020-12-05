#include "DMA_Plantuml.hpp"

#include "dma/base/INamedObject.hpp"
#include "dma/base/ForceLink.hpp"

DMA_FORCE_LINK_ANCHOR_CPP(INamedObject)

PUML_PACKAGE_BEGIN(DMA_Framework_Base)
    PUML_CLASS_BEGIN_CHECKED(DMA::INamedObject)
        PUML_METHOD(+, char* getName() const)
    PUML_CLASS_END()
PUML_PACKAGE_END()
