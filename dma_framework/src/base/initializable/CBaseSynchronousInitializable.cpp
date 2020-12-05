#pragma once

#include "DMA_Plantuml.hpp"
#include "dma/base/initializable/CBaseSynchronousInitializable.hpp"
#include "dma/base/ForceLink.hpp"

DMA_FORCE_LINK_ANCHOR_CPP(CBaseSynchronousInitializable)

namespace DMA
{
    tSyncInitOperationResult CBaseSynchronousInitializable::startInit()
    {
        tSyncInitOperationResult result;

        if(false == mbIsInitialized)
        {
            result = init();

            if(true == result.bIsOperationSuccessful)
            {
                mbIsInitialized = true;
                mCachedResult = result;
            }
        }
        else
        {
            result = mCachedResult;
        }

        return result;
    }

    tSyncInitOperationResult CBaseSynchronousInitializable::startShutdown()
    {
        tSyncInitOperationResult result;

        if(true == mbIsInitialized)
        {
            result = shutdown();

            if(true == result.bIsOperationSuccessful)
            {
                mbIsInitialized = false;
                mCachedResult = result;
            }
        }
        else
        {
            result = mCachedResult;
        }

        return result;
    }

    bool CBaseSynchronousInitializable::isInitialized () const
    {
        return mbIsInitialized;
    }
}

PUML_PACKAGE_BEGIN(DMA_Framework_Base)
    PUML_CLASS_BEGIN_CHECKED(DMA::ISynchronousInitializable)
        PUML_PURE_VIRTUAL_METHOD(+, virtual tSyncInitOperationResult startInit())
        PUML_PURE_VIRTUAL_METHOD(+, virtual tSyncInitOperationResult startShutdown() )
        PUML_PURE_VIRTUAL_METHOD(+, virtual virtual bool isInitialized () const)
    PUML_CLASS_END()

    PUML_CLASS_BEGIN_CHECKED(DMA::CBaseSynchronousInitializable)
        PUML_INHERITANCE_CHECKED(DMA::ISynchronousInitializable, implements)
        PUML_VIRTUAL_METHOD(+, virtual tSyncInitOperationResult startInit())
        PUML_VIRTUAL_METHOD(+, virtual tSyncInitOperationResult startShutdown() )
        PUML_VIRTUAL_METHOD(+, virtual virtual bool isInitialized () const)
        PUML_PURE_VIRTUAL_METHOD(#, virtual tSyncInitOperationResult init())
        PUML_PURE_VIRTUAL_METHOD(#, virtual tSyncInitOperationResult shutdown())
    PUML_CLASS_END()
PUML_PACKAGE_END()
