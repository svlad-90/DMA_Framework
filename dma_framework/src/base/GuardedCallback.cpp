#include "DMA_Plantuml.hpp"

#include "dma/base/GuardedCallback.hpp"
#include "dma/base/ForceLink.hpp"

DMA_FORCE_LINK_ANCHOR_CPP(GuardedCallback)

PUML_PACKAGE_BEGIN(DMA_Framework_Base)
    PUML_CLASS_BEGIN(DMA::detail::guarded_call<Func>)
        PUML_METHOD(+, detail::guarded_call<Func> guardCallback( Func target, tExpiredCallback mExpiredCallback = {} ))
        PUML_USE_DEPENDENCY(DMA::tGuard, 1, 1, contains)
    PUML_CLASS_END()

    PUML_CLASS_BEGIN_CHECKED(DMA::tCallbackGuardian)
        PUML_METHOD(+, DMA::detail::guarded_call<Func> guardCallback( Func target, tExpiredCallback mExpiredCallback = {} ))
        PUML_COMPOSITION_DEPENDENCY_CHECKED(DMA::tGuarded, 1, 1, contains)
        PUML_USE_DEPENDENCY(DMA::detail::guarded_call<Func>, 1, *, creates)
    PUML_CLASS_END()
PUML_PACKAGE_END()
