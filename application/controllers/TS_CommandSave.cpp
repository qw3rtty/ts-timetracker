/**
 * TS-CommandSave
 *
 * Save command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <sstream>

#include "TS_Application.h"
#include "TS_Command.h"
#include "TS_CommandSave.h"

/**
 * @inherit
 */
TS_CommandSave::TS_CommandSave(char *arguments) : TS_Command(arguments)
{
    this->successfullySaved = false;
}

/**
 * @inherit
 */
bool TS_CommandSave::execute()
{
    this->prepare();

    if (this->isTestMode)
    {
        return true;
    }

    if (application->getChoosedProject() >= 0)
    {
        std::stringstream entryBuffer;
        entryBuffer << application->startTimestamp
            << ";" << application->endTimestamp
            << ";" << this->arguments;

        this->successfullySaved = application->model.save(entryBuffer.str());
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandSave::prepare()
{
    return true;
}


/**
 * @inherit
 */
std::ostringstream TS_CommandSave::getMessage()
{
    std::ostringstream message;

    if (application->getChoosedProject() >= 0)
    {
        if (this->successfullySaved)
        {
            message << "Successfully saved new time track!";
        }
        else
        {
            message << "Error on saving new time track! Try again ...";
        }
    }
    else
    {
        message << "You have to choose a project!" << std::endl;
        message << "Type 'help' to get more informations.";
    }

    return message;
}
