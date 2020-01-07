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

#include "TS_ConfigReader.h"
#include "TS_Application.h"
#include "TS_CommandTouch.h"

/**
 * @inherit
 */
TS_CommandTouch::TS_CommandTouch(char *arguments) : TS_Command(arguments)
{
    this->touchedSuccessful = false;
}

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
        this->touchedSuccessful = false;
        return false;
    }

    std::stringstream newProjectPath;
    newProjectPath << this->storePath << this->arguments;

    std::ofstream newProject(newProjectPath.str());
    newProject.close();

    application->clearProjectList();
    this->touchedSuccessful = true;

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

/**
 * @inherit
 */
std::ostringstream TS_CommandTouch::getMessage()
{
    std::ostringstream message;

    message << "No project name entered or something went wrong!";
    if (this->touchedSuccessful)
    {
        message.str("");
        message << "New project '" << this->arguments << "' successful created.";
    }

    return message;
}
