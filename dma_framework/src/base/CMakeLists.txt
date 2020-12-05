DMA_add_subdirectory_with_clang_tidy (initializable)

add_library(DMA_framework_base STATIC
            Guard.cpp
            GuardedCallback.cpp
            INamedObject.cpp)

target_link_libraries(DMA_framework_base PUBLIC DMA_Plantuml DMA_framework_base_initializable)
