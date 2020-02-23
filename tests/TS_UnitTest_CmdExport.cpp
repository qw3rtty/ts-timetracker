/**
 * TS-UnitTest Command Export
 *
 * Unit test for the Export command.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <cassert>
#include <string>

#include <cstring>
#include <cstdlib>

#include "TS_CommandExport.h"

int main()
{
    char* arguments = getenv("HOME");
    strcat(arguments, "/Downloads/");

    TS_CommandExport* cmd = new TS_CommandExport(arguments);

    assert(cmd->execute());
    std::cout << "TS_CommandExport passed" << " \u2713" << std::endl;

    return 0;
}
