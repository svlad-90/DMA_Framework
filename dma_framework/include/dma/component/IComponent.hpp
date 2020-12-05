#pragma once

#include "dma/base/INamedObject.hpp"
#include "dma/base/initializable/CBaseSynchronousInitializable.hpp"

namespace DMA
{
    class IComponent :
    public INamedObject,
    public CBaseSynchronousInitializable
    {
    public:
        IComponent();
        virtual ~IComponent() = default;
    };
}
