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
    char name[] = "github";
    char* arguments = name;

    TS_ModelFilesystem* model = new TS_ModelFilesystem();
    model->setProject(arguments);

    assert(model->getName() != "");

    std::cout << "TS_ModelFilesystem passed" << " \u2713" << std::endl;

    return 0;
}
