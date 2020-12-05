#pragma once

namespace DMA
{
    class INamedObject
    {
    public:
        virtual ~INamedObject() = default;

        /**
         * @brief getName - returns the name of the object. Intention is to use
         * the provided name mainly for tracing purpose.
         * @return - the name of the object.
         */
        virtual char* getName() const = 0;
    };
}
