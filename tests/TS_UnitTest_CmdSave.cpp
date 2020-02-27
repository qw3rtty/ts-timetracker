/**
 * TS-UnitTest Command Save
 *
 * Unit test for the Save command.
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
#include "TS_ModelFilesystem.h"
#include "TS_CommandSave.h"

int main()
{
    TS_ModelFilesystem* model = new TS_ModelFilesystem();

    TS_CommandSave* cmd = new TS_CommandSave(nullptr, model);
    cmd->setTestMode(true);

    assert(cmd->execute());
    std::cout << "TS_CommandSave passed" << " \u2713" << std::endl;

    return 0;
}
