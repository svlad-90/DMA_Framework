#pragma once

#include "functional"
#include <type_traits>

#include "dma/base/Guard.hpp"

namespace DMA
{

typedef std::function<void(void)> tExpiredCallback;

namespace detail
{
template <typename Func >
class guarded_call
{
public:
    guarded_call( Func f, tGuard g, tExpiredCallback expiredCallback = {} ):
        mFunc( std::move( f ) ),
        mGuard( g ),
        mExpiredCallback( std::move( expiredCallback ) )
    {}

    template<typename... Args>
    typename std::enable_if<!std::is_same<typename std::result_of<Func(Args&&...)>::type, void>::value,
                            typename std::result_of<Func(Args&&...)>::type>::type
    operator () ( Args&&... args)
    {
        using tResult = typename std::result_of<Func(Args&&...)>::type;
        tResult res;

        if ( mGuard.isAlive() )
        {
            res = mFunc( std::forward<Args>( args )... );
        }
        else
        {
            res = tResult{};

            if ( mExpiredCallback )
            {
                mExpiredCallback();
            }
        }

        return  res;
    }

    template<typename... Args>
    typename std::enable_if<std::is_same<typename std::result_of<Func(Args&&...)>::type, void>::value, void>::type
    operator () ( Args&&... args)
    {
        if ( mGuard.isAlive() )
        {
            mFunc( std::forward<Args>( args )... );
        }
        else if ( mExpiredCallback )
        {
            mExpiredCallback();
        }
    }

private:
    Func mFunc;
    tGuard mGuard;
    tExpiredCallback mExpiredCallback;
};
}

/**
 * @brief The tCallbackGuardian class
 * This class allows you to create guarded callbacks, which will check at
 * runtime, whether closured "this" is still alive.
 *
 * How to use?
 *
 * 1. Inherit from tCallbackGuardian
 * 2. Use guardCallback method to created protected callback:
 *
 *   auto callback = guardCallback([this]()
 *   {
 *       // do something
 *   });
 *
 * 3. Pass created callback elsewhere.
 *
 * Wrapped callback will call the nested one, ONLY if it "this" is still alive.
 */
class tCallbackGuardian
{
public:
    template <typename Func>
    detail::guarded_call<Func> guardCallback( Func target, tExpiredCallback mExpiredCallback = {} )
    {
        return mExpiredCallback ?
               detail::guarded_call<Func>( std::move( target ),  mGuarded.getGuard(),  std::move( mExpiredCallback ) ) :
               detail::guarded_call<Func>( std::move( target ),  mGuarded.getGuard() );
    }

private:
    tGuarded mGuarded;
};
}
