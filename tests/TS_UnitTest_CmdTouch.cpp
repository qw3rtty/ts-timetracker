/**
 * TS-UnitTest Command Touch
 *
 * Unit test for the Touch command.
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

#include "TS_Helper.h"
#include "TS_CommandTouch.h"

int main()
{
    TS_CommandTouch* cmd = new TS_CommandTouch(nullptr);
    cmd->setTestMode(true);

    assert(cmd->execute());
    std::cout << "TS_CommandTouch passed" << " \u2713" << std::endl;

    return 0;
}
