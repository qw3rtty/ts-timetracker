/**
 * TS-UnitTest
 *
 * Main unit test.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cassert>

#include "../application/controllers/headers/TS_Base.h"
#include "../application/controllers/headers/TS_CommandDelegator.h"

int main()
{
    std::cout << "Unit tests starting..." << std::endl;

    assert(commandDelegator->unitTest());
    std::cout << "TS_CommandDelegator passed " << " \u2713" << std::endl;

    std::cout << "All tests passed" << " \u2713" << std::endl;
    return 0;
}