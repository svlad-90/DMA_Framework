#include <iostream>
#include <string>

#include "DMA_Plantuml.hpp"

#include "dma/base/ForceLink.hpp"

static const std::string diagramExportPath = std::string(PUML_EXPORT_DIR);

static void traceExportResult(const std::string& exportPath,
                              const std::string& exportPackage,
                              const DMA::PlantUML::Creator::tClassDiagramExportResult& exportResult)
{
    std::string prefix;

    if(true == exportResult.bIsSuccessful)
    {
        prefix = "[Success]";
    }
    else
    {
        prefix = "[Failure]";
    }

    std::cout << prefix
              << ": exportPath - "
              << exportPath;

    if(false == exportPackage.empty())
    {
        std::cout << "; exportPackage - "
        << exportPackage;
    }

    if(false == exportResult.error.empty())
    {
        std::cout << "; error - "
                  << exportResult.error;
    }

    std::cout << std::endl;
}

int main()
{
    DMA_FORCE_LINK_REFERENCE(Guard)
    DMA_FORCE_LINK_REFERENCE(GuardedCallback)

    DMA::PlantUML::Creator::getInstance().initialize();
    DMA::PlantUML::Creator::getInstance().setBackgroundColor("#FEFEFE");

    {
        auto exportResult = DMA::PlantUML::Creator::getInstance().exportClassDiagram(diagramExportPath);
        traceExportResult(diagramExportPath, "", exportResult);
    }

    {
        auto exportResult = DMA::PlantUML::Creator::getInstance().exportAllPackageClassDiagrams(diagramExportPath, false);

        for(const auto& exportResultItem : exportResult)
        {
            traceExportResult(diagramExportPath, exportResultItem.first, exportResultItem.second);
        }
    }

    {
        auto exportResult = DMA::PlantUML::Creator::getInstance().exportAllPackageClassDiagrams(diagramExportPath, true);

        for(const auto& exportResultItem : exportResult)
        {
            traceExportResult(diagramExportPath, exportResultItem.first, exportResultItem.second);
        }
    }
}
