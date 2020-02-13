/**
 * TS-Helper
 *
 * Helper class for application.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <ctime>
#include <string>
#include <ostream>

#include "TS_Application.h"
#include "TS_Helper.h"
#include "TS_ConfigReader.h"

/**
 * Constructor
 */
TS_Helper::TS_Helper()
{
    this->color = "\033[0;33m";
    this->noColor = "\033[0m";
    this->tab = "\t";
    this->doubleTab = "\t\t";
}

/**
 * Format given timestamp
 * > format is configured in config file
 * > if no format is set, we use the default format
 * @param   std::time_t     timestamp       - Timestamp which should be formatted
 * @return  std::string     Formatted time string
 */
std::string TS_Helper::formatTimestamp(std::time_t timestamp)
{
    TS_ConfigReader config;
    if (!config.configLoaded)
    {
        return std::asctime(std::localtime(&timestamp));
    }

    char *date = new char[80];
    std::string format = config.getConfigEntry("timeFormat");
    std::strftime(date, 80, format.c_str(), std::localtime(&timestamp));

    return date;
}

/**
 * Get selected project name
 * @return  std::string
 */
std::string TS_Helper::getSelectedProjectName()
{
    application->model.setProject(application->getChoosedProject());
    return application->model.getName();
}
