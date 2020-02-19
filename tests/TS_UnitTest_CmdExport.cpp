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

#include "TS_Helper.h"
#include "TS_CommandExport.h"

int main()
{
    TS_CommandExport* cmd = new TS_CommandExport(nullptr);

    assert(cmd->execute());
    std::cout << "TS_CommandExport passed" << " \u2713" << std::endl;

    return 0;
}
