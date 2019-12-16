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
        std::cout << "You selected '" << application->model.getProjectName() << "'" << std::endl;
    }
    else
    {
        application->setChoosedProject(-1);
        std::cout << "You selected an non existing project!" << std::endl;
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