#pragma once

#include "dma/base/initializable/ISynchronousInitializable.hpp"

namespace DMA
{
    class CBaseSynchronousInitializable : public ISynchronousInitializable
    {
    public:
        virtual tSyncInitOperationResult startInit() final override;
        virtual tSyncInitOperationResult startShutdown() final  override;
        virtual bool isInitialized () const final override;

    protected:

        /**
         * @brief init - logic of initialization, to be implemented by the
         * client
         * @return - instance of the tSyncInitOperationResult with result of operation
         */
        virtual tSyncInitOperationResult init() = 0;

        /**
         * @brief shutdown - logic of initialization, to be implemented by the
         * client
         * @return - instance of the tSyncInitOperationResult with result of operation
         */
        virtual tSyncInitOperationResult shutdown() = 0;

    private:
        bool mbIsInitialized = false;
        tSyncInitOperationResult mCachedResult;
    };
}
