/**
 * TS-UnitTest Model Filesystem
 *
 * Unit test for the filesystem model.
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

#include "TS_ModelFilesystem.h"

int main()
{
    char name[] = "__timetracker";
    char* arguments = name;

    TS_ModelFilesystem* model = new TS_ModelFilesystem();
    model->setProject(arguments);

    assert(model->getName() != "");
    assert(model->getTimeAmount() == 0);

    std::cout << "TS_ModelFilesystem passed" << " \u2713" << std::endl;

    return 0;
}
