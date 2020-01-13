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

#include <iostream>
#include <cassert>

#include "TS_ConfigReader.h"
#include "TS_Helper.h"
#include "TS_Info.h"
#include "TS_Application.h"
#include "TS_CommandHelp.h"
#include "TS_CommandList.h"
#include "TS_CommandRemove.h"
#include "TS_CommandTimestamp.h"
#include "TS_CommandTouch.h"

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

    TS_CommandRemove cmdRemove(testArgument);
    cmdRemove.setTestMode(true);
    assert(cmdRemove.execute());
    std::cout << "TS_CommandRemove passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    TS_CommandTimestamp cmdTime(testArgument);
    assert(cmdTime.execute());
    assert(cmdTime.getTimestamp() != -1);
    std::cout << "TS_CommandTimestamp passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    TS_CommandTouch cmdTouch(testArgument);
    cmdTouch.setTestMode(true);
    assert(cmdTouch.execute());
    std::cout << "TS_CommandTouch passed " << helper.color << " \u2713" << helper.noColor << std::endl;

    std::cout << std::endl;
    std::cout << helper.color << "All tests passed" << " \u2713" << helper.noColor << std::endl;
    return 0;
}