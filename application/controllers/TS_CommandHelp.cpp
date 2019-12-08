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

#include "../../helpers/headers/TS_Helper.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandHelp.h"

/**
 * @inherit
 */
TS_CommandHelp::TS_CommandHelp(char *arguments) : TS_Command(arguments)
{}

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

    TS_Helper helper;
    std::cout << "Available commands:" << std::endl;
    std::cout << "- help:" << helper.doubleTab << "Show's the help menu" << std::endl;
    std::cout << "- touch: <name>" << helper.tab << "Create's a new project" << std::endl;
    std::cout << "- rm <name>:" << helper.tab << "Delete's entered project" << std::endl;
    std::cout << "- ls <item>:" << helper.tab << "List selected items (use 'projects' or 'config')" << std::endl;
    std::cout << "- use <n>:" << helper.tab << "Set project to track time on, a number from 'list' command" << std::endl;
    std::cout << "- start:" << helper.tab << "Start's timetracking" << std::endl;
    std::cout << "- stop:" << helper.doubleTab << "Stop's timetracking" << std::endl;
    std::cout << "- save:" << helper.doubleTab << "Save new timetrack depending on settings" << std::endl;

    return true;
}

/**
 * @inherit
 */
bool TS_CommandHelp::prepare()
{
    return true;
}