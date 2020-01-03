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
#include <sstream>

#include "TS_Helper.h"
#include "TS_Command.h"
#include "TS_CommandHelp.h"

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
 * @inherit
 */
std::ostringstream TS_CommandHelp::getMessage()
{
    std::ostringstream message;

    TS_Helper helper;
    message << "Available commands:" << std::endl;
    message << "- help:" << helper.doubleTab << "Show's the help menu" << std::endl;
    message << "- touch: <name>" << helper.tab << "Create's a new project" << std::endl;
    message << "- rm <name>:" << helper.tab << "Delete's entered project" << std::endl;
    message << "- ls <item>:" << helper.tab << "List selected items (use 'projects', 'config' or 'times')" << std::endl;
    message << "- use <n>:" << helper.tab << "Set project to track time on, a number from 'list' command" << std::endl;
    message << "- start:" << helper.tab << "Start's timetracking" << std::endl;
    message << "- stop:" << helper.doubleTab << "Stop's timetracking" << std::endl;
    message << "- save:" << helper.doubleTab << "Save new timetrack depending on settings";

    return message;
}
