/**
 * TS-UnitTest Command Use
 *
 * Unit test for the Use command.
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
#include "TS_CommandUse.h"

int main()
{
    char project[] = "0";
    char* arguments = project;
    TS_ModelFilesystem* model = new TS_ModelFilesystem();

    TS_CommandUse* cmd = new TS_CommandUse(arguments, model);

    assert(cmd->execute());
    std::cout << "TS_CommandUse passed" << " \u2713" << std::endl;

    return 0;
}
