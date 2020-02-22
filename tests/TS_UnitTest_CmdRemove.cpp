/**
 * TS-UnitTest Command Remove
 *
 * Unit test for the Remove command.
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
#include "TS_CommandRemove.h"

int main()
{
    TS_CommandRemove* cmd = new TS_CommandRemove(nullptr);
    cmd->setTestMode(true);

    assert(cmd->execute());
    std::cout << "TS_CommandRemove passed" << " \u2713" << std::endl;

    return 0;
}
