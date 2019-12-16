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
{}

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

    int project = application->getChoosedProject();
    if (project >= 0)
    {
        std::stringstream entryBuffer;
        entryBuffer << application->startTimestamp << ";" << application->endTimestamp;

        bool successfullySaved = application->model.save(entryBuffer.str());
        if (successfullySaved)
        {
            std::cout << "Successfully saved new time track!" << std::endl;
        }
        else
        {
            std::cout << "Error on saving new time track! Try again ..." << std::endl;
        }
    }
    else
    {
        std::cout << "You have to choose a project!" << std::endl;
        std::cout << "Type 'help' to get more informations." << std::endl;
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