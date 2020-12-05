DMA_add_subdirectory_with_clang_tidy (base)
DMA_add_subdirectory_with_clang_tidy (component)
DMA_add_subdirectory_with_clang_tidy (event)

if(DMA_GENERATE_CLASS_DIAGRAMS)
    add_definitions(-DPUML_EXPORT_DIR="${PROJECT_SOURCE_DIR}/../md/dev_docs/puml")
    add_executable(CreateClassDiagrams CreateClassDiagrams.cpp)
    target_link_libraries(CreateClassDiagrams
                          DMA_framework_base
                          DMA_framework_component
                          DMA_Plantuml)
endif(DMA_GENERATE_CLASS_DIAGRAMS)
