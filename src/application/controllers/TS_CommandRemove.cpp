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

#include "TS_Helper.h"
#include "TS_IModel.h"
#include "TS_CommandRemove.h"

/**
 * @inherit
 */
TS_CommandRemove::TS_CommandRemove(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{
    this->successfullyRemoved = -1;
}

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
        return false;
    }

    std::stringstream deleteProjectPath;
    deleteProjectPath << this->storePath << this->arguments;

    this->successfullyRemoved = std::remove(deleteProjectPath.str().c_str());
    this->model->clearProjectListCache();

    return true;
}

/**
 * @inherit
 */
bool TS_CommandRemove::prepare()
{
    this->storePath = TS_ConfigReader::getProjectsPath();

    return true;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandRemove::getMessage()
{
    std::ostringstream message;

    if (this->arguments == nullptr)
    {
        message << "No project name entered!";
    }

    if (this->successfullyRemoved == 0)
    {
        message.str("");
        message << "Project '" << this->arguments << "' successful deleted.";
    }

    return message;
}
