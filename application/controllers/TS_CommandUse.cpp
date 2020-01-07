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

    application->setChoosedProject(std::stoi(this->arguments));
    if (application->getChoosedProject() >= 0)
    {
        application->model.setSelectedProjectKey(application->getChoosedProject());
    }
    else
    {
        application->setChoosedProject(-1);
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

    if (application->getChoosedProject() >= 0)
    {
        message << "You selected '" << application->model.getProjectName() << "'";
    }
    else
    {
        message << "You selected an non existing project!";
    }

    return message;
}
