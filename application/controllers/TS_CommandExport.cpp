/**
 * TS-CommandExport
 *
 * Export command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <string>
#include <fstream>

#include "TS_Application.h"
#include "TS_ConfigReader.h"
#include "TS_Command.h"
#include "TS_CommandExport.h"

/**
 * @inherit
 */
TS_CommandExport::TS_CommandExport(char *arguments) : TS_Command(arguments)
{
    this->successfulExport = false;
}

/**
 * @inherit
 */
bool TS_CommandExport::execute()
{
    this->prepare();

    if (this->exportPath.length() <= 0)
    {
        return false;
    }

    // TODO: specify export path!
    std::ostringstream fullExportPath;
    fullExportPath << this->exportPath.c_str() << ".csv";

    std::ifstream projectFile(this->exportPath.c_str(), std::ios::binary);
    std::ofstream exportFile(fullExportPath.str(), std::ios::binary);

    exportFile << this->createCsvHeadline() << std::endl;
    exportFile << projectFile.rdbuf();

    projectFile.close();
    exportFile.close();

    this->successfulExport = true;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandExport::prepare()
{
    TS_ConfigReader config;
    if (!config.configLoaded)
    {
        return false;
    }

    std::ostringstream path;
    application->model.setSelectedProjectKey( application->getChoosedProject() );

    path << config.getConfigEntry("projectsPath");
    path << application->model.getProjectName();

    this->exportPath = path.str();

    return true;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandExport::getMessage()
{
    std::ostringstream message;

    if (this->successfulExport)
    {
        message << "Export was successful.";
    }
    else
    {
        message << "Error during export!" << std::endl;
        message << "Please try again.";
    }

    return message;
}

/**
 * Create headline for exported CSV file
 * @return  std::string
 */
std::string TS_CommandExport::createCsvHeadline()
{
    return "Start time;End time; Comment";
}
