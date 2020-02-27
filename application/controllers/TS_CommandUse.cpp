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
#include "TS_IModel.h"
#include "TS_Command.h"
#include "TS_CommandUse.h"

/**
 * @inherit
 */
TS_CommandUse::TS_CommandUse(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
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
    this->model->setProject(this->arguments);
    if (this->model->getSelectedProject() == nullptr)
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

    if (this->model->getSelectedProject() != nullptr)
    {
        message << "You selected '" << this->model->getName() << "'";
    }
    else
    {
        message << "You selected an non existing project!";
    }

    return message;
}
