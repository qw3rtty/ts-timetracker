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

#include "TS_ModelFilesystem.h"
#include "TS_CommandHelp.h"

int main()
{
    TS_ModelFilesystem* model = new TS_ModelFilesystem();
    TS_CommandHelp* cmd = new TS_CommandHelp(nullptr, model);

    assert(cmd->execute());
    std::cout << "TS_CommandHelp passed" << " \u2713" << std::endl;

    return 0;
}
