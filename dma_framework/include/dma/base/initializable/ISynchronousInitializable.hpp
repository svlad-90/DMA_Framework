#pragma once

namespace DMA
{
    struct tSyncInitOperationResult
    {
        bool bIsOperationSuccessful = false;
        int returnCode = 0;
    };

    /**
     * @brief The ISynchronousInitializable class - class, which can be
     * initialized in a synchronous way
     */
    class ISynchronousInitializable
    {
    public:
        virtual ~ISynchronousInitializable() = default;

        /**
         * @brief startInit - inits an object
         * @return - instance of the tSyncInitOperationResult with result of operation
         */
        virtual tSyncInitOperationResult startInit() = 0;

        /**
         * @brief startShutdown - shutdowns an object
         * @return - instance of the tSyncInitOperationResult with result of operation
         */
        virtual tSyncInitOperationResult startShutdown() = 0;

        /**
         * @brief isInitialized - shows, whether object is initialized or not.
         * @return - return the object's initialization status.
         */
        virtual bool isInitialized () const = 0;
    };
}
