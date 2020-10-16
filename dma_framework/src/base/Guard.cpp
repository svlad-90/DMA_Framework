/**
 * @file    Guard.cpp
 * @author  vgoncharuk
 * @brief   Implementation of the guard idiom
 */

#include "DMA_Plantuml.hpp"

#include "dma/base/ForceLink.hpp"
#include "dma/base/Guard.hpp"

DMA_FORCE_LINK_ANCHOR_CPP(Guard)

namespace DMA
{
    // START tGuard
    tGuard::tGuard( const tGuardedElement& guardedElement ):
    mGuardElement(guardedElement)
    {}

    bool tGuard::isAlive() const
    {
        return false == mGuardElement.expired();
    }
    // END tGuarded

    // START tGuarded
    tGuarded::tGuarded():
    mGuardedElement(std::make_shared<int>(0))
    {}

    tGuard tGuarded::getGuard() const
    {
        return tGuard(mGuardedElement);
    }
    // END tGuarded
}

PUML_PACKAGE_BEGIN(DMA_Framework_Base)
    PUML_CLASS_BEGIN_CHECKED(DMA::tGuard)
        PUML_METHOD(+, tGuard( const tGuardedElement& guardedElement ))
        PUML_METHOD(+, bool isAlive() const)
    PUML_CLASS_END()

    PUML_CLASS_BEGIN_CHECKED(DMA::tGuarded)
        PUML_METHOD(+, tGuarded())
        PUML_METHOD(+, tGuard getGuard() const)
        PUML_USE_DEPENDENCY_CHECKED(DMA::tGuard, 1, *, creates)
    PUML_CLASS_END()
PUML_PACKAGE_END()
