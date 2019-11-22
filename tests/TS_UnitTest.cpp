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

#include "../application/controllers/headers/TS_Base.h"
#include "../application/controllers/headers/TS_CommandDelegator.h"
#include "../application/controllers/headers/TS_Command.h"
#include "../application/controllers/headers/TS_CommandHelp.h"

int main()
{
    std::cout << "Unit tests starting..." << std::endl;

    assert(commandDelegator->unitTest());
    std::cout << "TS_CommandDelegator passed " << " \u2713" << std::endl;

    TS_Command cmd;
    assert(!cmd.execute());
    std::cout << "TS_Command passed " << " \u2713" << std::endl;

    TS_CommandHelp cmdHelp;
    assert(cmdHelp.execute());
    std::cout << "TS_CommandHelp passed " << " \u2713" << std::endl;

    std::cout << "All tests passed" << " \u2713" << std::endl;
    return 0;
}