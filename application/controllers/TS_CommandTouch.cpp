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

#include "./headers/TS_Command.h"
#include "./headers/TS_CommandTouch.h"

/**
 * @inherit
 */
TS_CommandTouch::TS_CommandTouch(char *arguments) : TS_Command(arguments)
{}

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



    return true;
}

/**
 * @inherit
 */
bool TS_CommandTouch::prepare()
{
    return true;
}