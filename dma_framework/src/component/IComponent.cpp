#include "dma/component/IComponent.hpp"

#include "DMA_Plantuml.hpp"
#include "dma/base/ForceLink.hpp"

DMA_FORCE_LINK_ANCHOR_CPP(IComponent)

namespace DMA
{
    IComponent::IComponent()
    {}
}

PUML_PACKAGE_BEGIN(DMA_Framework_Component)
    PUML_CLASS_BEGIN_CHECKED(DMA::IComponent)
        PUML_INHERITANCE_CHECKED(DMA::INamedObject, implements)
        PUML_INHERITANCE_CHECKED(DMA::CBaseSynchronousInitializable, extends)
    PUML_CLASS_END()
PUML_PACKAGE_END()
