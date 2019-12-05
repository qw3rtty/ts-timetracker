/**
 * TS-UnitTest
 *
 * Main unit test.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cassert>

#include "../config/TS_ConfigReader.h"
#include "../helpers/headers/TS_Helper.h"
#include "../helpers/headers/TS_Info.h"
#include "../application/controllers/headers/TS_Base.h"
#include "../application/controllers/headers/TS_Application.h"
#include "../application/controllers/headers/TS_Command.h"
#include "../application/controllers/headers/TS_CommandHelp.h"
#include "../application/controllers/headers/TS_CommandList.h"
#include "../application/controllers/headers/TS_CommandTimestamp.h"

int main()
{
    char *testArgument;
    TS_Helper helper;

    TS_Info info;
    info.welcome();

    std::cout << helper.color << "Unit tests starting..." << helper.noColor << std::endl;
    std::cout << std::endl;

    TS_ConfigReader config;
    assert(config.configLoaded);
    std::cout << "TS_ConfigReader passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    assert(application->unitTest());
    std::cout << "TS_Application passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    TS_Command cmd(testArgument);
    assert(!cmd.execute());
    std::cout << "TS_Command passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    TS_CommandHelp cmdHelp(testArgument);
    cmdHelp.setTestMode(true);
    assert(cmdHelp.execute());
    std::cout << "TS_CommandHelp passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    TS_CommandList cmdList(testArgument);
    cmdList.setTestMode(true);
    assert(cmdList.execute());
    std::cout << "TS_CommandList passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    TS_CommandTimestamp cmdTime(testArgument);
    assert(cmdTime.execute());
    assert(cmdTime.getTimestamp() != -1);
    std::cout << "TS_CommandTimestamp passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    std::cout << std::endl;
    std::cout << helper.color << "All tests passed" << " \u2713" << helper.noColor << std::endl;
    return 0;
}