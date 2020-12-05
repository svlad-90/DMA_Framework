add_library(DMA_framework_base_initializable STATIC
            CBaseSynchronousInitializable.cpp)

target_link_libraries(DMA_framework_base_initializable PUBLIC DMA_Plantuml)
