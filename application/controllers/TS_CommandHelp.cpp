/**
 * TS-CommandHelp
 *
 * Help command
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
#include "./headers/TS_CommandHelp.h"

/**
 * @inherit
 */
TS_CommandHelp::TS_CommandHelp()
{}

/**
 * @inherit
 */
bool TS_CommandHelp::execute()
{
    this->prepare();

    std::cout << "HELP IS COMING" << std::endl;
    std::cout << "Please hang on a while..." << std::endl;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandHelp::prepare()
{
    return true;
}