/**
 * TS-UnitTest ConfigReader
 *
 * Unit test for the config reader.
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

#include "TS_ConfigReader.h"

int main()
{
    TS_ConfigReader* config = new TS_ConfigReader();

    assert(config->configLoaded);
    std::cout << "TS_ConfigReader config loaded passed" << " \u2713" << std::endl;

    assert(config->getConfigEntry("timeFormat") == "%d.%m.%Y %T");
    assert(config->getConfigEntry("storage") == "filesystem");
    std::cout << "TS_ConfigReader getConfigEntry() passed" << " \u2713" << std::endl;

    return 0;
}