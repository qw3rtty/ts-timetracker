/**
 * TS-CommandUse
 *
 * Select project command
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

#include "TS_Application.h"
#include "TS_Command.h"
#include "TS_CommandUse.h"

/**
 * @inherit
 */
TS_CommandUse::TS_CommandUse(char *arguments) : TS_Command(arguments)
{}

/**
 * @inherit
 */
bool TS_CommandUse::execute()
{
    this->prepare();

    if (this->isTestMode)
    {
        return true;
    }

    application->setSelectedProject(this->arguments);
    if (application->getSelectedProject() != nullptr)
    {
        application->model.setProject(application->getSelectedProject());
    }
    else
    {
        application->setSelectedProject(nullptr);
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandUse::prepare()
{
    return true;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandUse::getMessage()
{
    std::ostringstream message;

    if (application->getSelectedProject() != nullptr)
    {
        message << "You selected '" << application->model.getName() << "'";
    }
    else
    {
        message << "You selected an non existing project!";
    }

    return message;
}
