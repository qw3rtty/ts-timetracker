/**
 * TS-CommandConfig
 *
 * List config options
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <string>
#include <vector>

#include "TS_ConfigReader.h"
#include "TS_IModel.h"
#include "TS_CommandConfig.h"

/**
 * @inherit
 */
TS_CommandConfig::TS_CommandConfig(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{
    this->configReader = new TS_ConfigReader();
}

/**
 * Destructor
 */
TS_CommandConfig::~TS_CommandConfig()
{
    free(this->configReader);
}

/**
 * @inherit
 */
bool TS_CommandConfig::execute()
{
    return this->prepare();
}

/**
 * @inherit
 */
bool TS_CommandConfig::prepare()
{
    return this->configReader->configLoaded;
}

/**
 * Show all settings in config
 */
void TS_CommandConfig::showConfig()
{
    if (!this->configReader->configLoaded)
    {
        return;
    }

    if (!this->isTestMode)
    {
        this->configReader->showConfig();
    }
}

/**
 * @inherit
 */
std::ostringstream TS_CommandConfig::getMessage()
{
    std::ostringstream message;
    this->showConfig();

    return message;
}
