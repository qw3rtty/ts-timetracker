/**
 * TS-CommandTimestamp
 *
 * Creates current timestamp
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <string>
#include <ctime>

#include "TS_ConfigReader.h"
#include "TS_Command.h"
#include "TS_CommandTimestamp.h"

/**
 * @inherit
 */
TS_CommandTimestamp::TS_CommandTimestamp(char *arguments) : TS_Command(arguments)
{}

/**
 * @inherit
 */
bool TS_CommandTimestamp::execute()
{
    this->prepare();

    if (this->timestamp == -1)
    {
        std::cout << "Error by getting current timestamp." << std::endl;
        return false;
    }

    this->showTime();

    return true;
}

/**
 * @inherit
 */
bool TS_CommandTimestamp::prepare()
{
    this->timestamp = std::time(nullptr);
    return true;
}

/**
 * Get started timestamp
 * @return  std::time_t  - Current timestamp
 */
std::time_t TS_CommandTimestamp::getTimestamp()
{
    return this->timestamp;
}

/**
 * Get formatted date
 * > format is configured in config file
 * > if no format is set, we use the default format
 * @return  char*   - Formatted time string
 */
char *TS_CommandTimestamp::getFormattedDate()
{
    TS_ConfigReader config;
    if (!config.configLoaded)
    {
        return std::asctime(std::localtime(&this->timestamp));
    }

    char *date = new char[80];
    std::string format = config.getConfigEntry("timeFormat");
    std::strftime(date, 80, format.c_str(), std::localtime(&this->timestamp));

    return date;
}

/**
 * Show's the time
 */
void TS_CommandTimestamp::showTime()
{
    std::cout << "Current time: " << this->getFormattedDate() << std::endl;
}