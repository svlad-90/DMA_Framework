DMA_add_subdirectory_with_clang_tidy (base)

if(DMA_GENERATE_CLASS_DIAGRAMS)
    add_definitions(-DPUML_EXPORT_DIR="${PROJECT_SOURCE_DIR}/../md/dev_docs/puml")
    add_executable(CreateClassDiagrams CreateClassDiagrams.cpp)
    target_link_libraries(CreateClassDiagrams DMA_framework_base DMA_Plantuml)
endif(DMA_GENERATE_CLASS_DIAGRAMS)
