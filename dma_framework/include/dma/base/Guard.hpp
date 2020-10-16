#pragma once

/**
 * @file    Guard.hpp
 * @author  vgoncharuk
 * @brief   Declaration of the guard idiom
 */

#include <memory>

/**
 * Guard - this concept can be used in order to check at runtime, whether the
 * target entity is still alive or not.
 *
 * 1. Using composition, place tGuarded as a field to a target entity.
 * 2. Let that entity expose tGuard out of the contained tGuarded instance to
 * the outside world.
 * 3. Whenever needed - use obtained tGuard's isAlive metho to check, whether
 * the target entity is still alive.
 */
namespace DMA
{
    typedef std::shared_ptr<int> tGuardedElement;
    typedef std::weak_ptr<int> tGuardElement;

    class tGuard
    {
    public:
        tGuard( const tGuardedElement& guardedElement );
        bool isAlive() const;
    private:
        tGuardElement mGuardElement;
    };

    class tGuarded
    {
    public:
        tGuarded();
        tGuard getGuard() const;
    private:
        tGuardedElement mGuardedElement;
    };


}
