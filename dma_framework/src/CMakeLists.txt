################### CLANG_TIDY ############################
if( DMA_CLANG_TIDY_BUILD )
    message("-- [DMA_FRAMEWORK]: clang-tidy build.")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
    list(APPEND CMAKE_CXX_CLANG_TIDY
    "-format-style='file'"
    "-warnings-as-errors=*" )
endif()
################### CLANG_TIDY ( END ) ####################

################### DMA_FRAMEWORK #########################
set(TURN_OFF_RCC OFF)

if(NOT CMAKE_AUTORCC)
    set(CMAKE_AUTORCC ON)
    set(TURN_OFF_RCC ON)
endif()

include_directories(../../thirdparty/DMA_Plantuml/src)

add_subdirectory(../../thirdparty/DMA_Plantuml DMA_Plantuml)

#add_library(DMA_Framework MODULE
#    dltmessageanalyzerplugin.cpp
#    CDLTMessageAnalyzer.cpp
#    form.cpp
#    ${UI_HEADERS}
#    resources/dltmessageanalyzer.qrc)

#target_link_libraries(DMA_Framework
#    DMA_analyzer)

if(TURN_OFF_RCC)
    set(CMAKE_AUTORCC OFF)
    set(TURN_OFF_RCC OFF)
endif()
################### DMA_FRAMEWORK ( END ) #################