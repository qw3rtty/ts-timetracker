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

#include "TS_Helper.h"
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

    this->model->setProject(this->arguments);

    // TODO: add check for valid project selection!!
    if (this->model->getSelectedProject() == nullptr)
    {
        this->model->setProject(nullptr);
        return false;
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
    TS_Helper* helper = new TS_Helper();
    std::ostringstream message;

    if (this->model->getSelectedProject() != nullptr)
    {
        message << "You selected [" << helper->color << this->model->getName() << helper->noColor << "]";
    }
    else
    {
        message << "You selected an non existing project!";
    }

    return message;
}
