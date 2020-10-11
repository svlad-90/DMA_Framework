################### CPP ###################################
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
################### CPP ( END ) ###########################

################### HELPERS ###############################
include(cmake/CMakeLists_Helper.txt)
################### HELPERS ( END ) #######################

################### GOOGLE TEST ###########################
IF (WIN32)
  option(CMAKE_USE_WIN32_THREADS_INIT "using WIN32 threads" ON)
  option(gtest_disable_pthreads "Disable uses of pthreads in gtest." ON)
ENDIF()

project(googletest-download NONE)

include(ExternalProject)
configure_file(cmake/CMakeLists_gtest.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()
################### GOOGLE TEST ( END ) ###################

################### DMA_Plantuml ##########################
project(dma_plantuml-download NONE)

include(ExternalProject)
configure_file(cmake/CMakeLists_dma_plantuml.txt.in dma_plantuml-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dma_plantuml-download )
if(result)
  message(FATAL_ERROR "CMake step for DMA_Plantuml failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dma_plantuml-download )
if(result)
  message(FATAL_ERROR "Build step for DMA_PLantuml failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/dma_plantuml-src
                 ${CMAKE_CURRENT_BINARY_DIR}/dma_plantuml-build
                 EXCLUDE_FROM_ALL)
################### DMA_Plantuml ( END ) ##################

################### PROJECT ###############################
project (DMA_Framework)
enable_testing()

CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

#add_subdirectory(src)
add_subdirectory(test)
################### PROJECT ( END ) #######################
