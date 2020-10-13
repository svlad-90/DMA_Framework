#pragma once

/**
 * @file    TNumberedObject.hpp
 * @author  vgoncharuk
 * @brief   Declaration of the numbered object abstraction
 */

#include <cinttypes>
#include <atomic>

namespace DMA
{
    typedef uint64_t tObjectID;

    static const tObjectID INVALID_OBJECT_ID = static_cast<uint64_t>(-1);

    class INumberedObject
    {
    public:
        virtual ~INumberedObject() = default;
        virtual tObjectID getObjectID() const = 0;
    };

    template<typename T>
    class TNumberedObject : public INumberedObject
    {
    public:

        TNumberedObject():
        mObjectID(++sObjectID)
        {}

        virtual tObjectID getObjectID() const final override
        {
            return mObjectID;
        }

        static tObjectID getObjectIDCounter()
        {
            return sObjectID;
        }

    private:
        static std::atomic<tObjectID> sObjectID;
        tObjectID mObjectID;
    };

    template<typename T>
    std::atomic<tObjectID> TNumberedObject<T>::sObjectID(INVALID_OBJECT_ID);
}
