/**
 * TS-CommandRemove
 *
 * Remove a existing project
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
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandRemove.h"

/**
 * @inherit
 */
TS_CommandRemove::TS_CommandRemove(char *arguments) : TS_Command(arguments)
{}

/**
* @inherit
 */
bool TS_CommandRemove::execute()
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

    std::stringstream deleteProjectPath;
    deleteProjectPath << this->storePath << this->arguments;

    std::remove(deleteProjectPath.str().c_str());
    std::cout << "Project '" << this->arguments << "' successful deleted." << std::endl;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandRemove::prepare()
{
    TS_ConfigReader config;
    this->storePath = config.getConfigEntry("projectsPath");

    return true;
}