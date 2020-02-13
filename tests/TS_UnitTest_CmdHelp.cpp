/**
 * TS-UnitTest Command Help
 *
 * Unit test for the Help command.
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

#include "TS_CommandHelp.h"

int main()
{
    TS_CommandHelp* cmd = new TS_CommandHelp(NULL);

    assert(cmd->execute());
    std::cout << "TS_ConfigReader config loaded passed" << " \u2713" << std::endl;

    return 0;
}
