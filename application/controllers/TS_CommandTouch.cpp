/**
 * TS-CommandTouch
 *
 * Create a new project
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "../../config/TS_ConfigReader.h"
#include "./headers/TS_Application.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandTouch.h"

/**
 * @inherit
 */
TS_CommandTouch::TS_CommandTouch(char *arguments) : TS_Command(arguments)
{}

/**
 * @inherit
 */
bool TS_CommandTouch::execute()
{
    this->prepare();

    if (this->isTestMode)
    {
        return true;
    }

    if (this->arguments == nullptr)
    {
        std::cout << "No project name entered!" << std::endl;
        return false;
    }

    std::stringstream newProjectPath;
    newProjectPath << this->storePath << this->arguments;

    std::ofstream newProject(newProjectPath.str());
    newProject.close();

    std::cout << "New project '" << this->arguments << "' successful created." << std::endl;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandTouch::prepare()
{
    TS_ConfigReader config;
    this->storePath = config.getConfigEntry("projectsPath");

    return true;
}