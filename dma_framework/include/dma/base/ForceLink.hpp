#pragma once

/**
 * @file    ForceLink.hpp
 * @author  vgoncharuk
 * @brief   Declaration of the force link idiom
 */

/**
 * This idiom allows you to force linkage of the translation unit, which is not
 * actually being used by any part of your executable.
 *
 * How to use?
 *
 * 1. In your cpp, which you want to force to be linked place the line:
 * DMA_FORCE_LINK_ANCHOR_CPP(<YourFileNameWithoutExtension>)
 *
 * 2. In another cpp, in a function which is for sure linkedi into the
 * executable place the line:
 * DMA_FORCE_LINK_REFERENCE(<YourFileNameWithoutExtension>)
 *
 * 3. Somewhere in CMakeLists.txt activate the define:
 * add_definitions(-DDMA_FORCE_LINK_ON)
 *
 * 4. Build your executable.
 *
 * Note! Concept is activated ONLY if your build has a DMA_FORCE_LINK_ON define
 * active. Otherwise macro definitions will do nothing.
 */
#ifdef DMA_FORCE_LINK_ON
    #define DMA_FORCE_LINK_ANCHOR_CPP(x) int force_link_##x = 0;
    #define DMA_FORCE_LINK_REFERENCE(x){ extern int force_link_##x; force_link_##x = 1; }
#else
    #define DMA_FORCE_LINK_ANCHOR_CPP(x)
    #define DMA_FORCE_LINK_REFERENCE(x)
#endif
