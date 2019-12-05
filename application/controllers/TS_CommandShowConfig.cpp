/**
 * TS-CommandShowConfig
 *
 * Shows loaded config entries
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <stdio.h>

#include "../../config/TS_ConfigReader.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandShowConfig.h"

/**
 * Constructor
 */
TS_CommandShowConfig::TS_CommandShowConfig(char *arguments) : TS_Command(arguments)
{
    this->isTestMode = false;
}

/**
 * @inherit
 */
bool TS_CommandShowConfig::execute()
{
    this->prepare();

    TS_ConfigReader config;
    if (!config.configLoaded)
    {
        return false;
    }

    if (!this->isTestMode)
    {
        config.showConfig();
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandShowConfig::prepare()
{
    return true;
}

/**
 * Set test mode
 * @param testMode
 */
void TS_CommandShowConfig::setTestMode(bool testMode)
{
    this->isTestMode = testMode;
}