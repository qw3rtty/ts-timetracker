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
{
    this->isTestMode = false;
}

/**
 * @inherit
 */
bool TS_CommandHelp::execute()
{
    this->prepare();

    if (this->isTestMode)
    {
        return true;
    }

    std::cout << "Options and commands:" << std::endl;
    std::cout << "- help: Show's the help menu" << std::endl;
    std::cout << "- showConfig: Show's the loaded config values" << std::endl;
    std::cout << "- list: List all available projects" << std::endl;
    std::cout << "- set <number>: Set project to track time on, a number from 'list' command" << std::endl;
    std::cout << "- start: Start's timetracking" << std::endl;
    std::cout << "- stop: Stop's timetracking" << std::endl;
    std::cout << "- save: Save new timetrack depending on settings" << std::endl;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandHelp::prepare()
{
    return true;
}

/**
 * Set test mode
 * @param testMode
 */
void TS_CommandHelp::setTestMode(bool testMode)
{
    this->isTestMode = testMode;
}