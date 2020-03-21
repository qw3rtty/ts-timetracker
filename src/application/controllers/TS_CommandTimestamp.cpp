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

#include "TS_Helper.h"
#include "TS_IModel.h"
#include "TS_Command.h"
#include "TS_CommandTimestamp.h"

/**
 * @inherit
 */
TS_CommandTimestamp::TS_CommandTimestamp(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{}

/**
 * @inherit
 */
bool TS_CommandTimestamp::execute()
{
    this->prepare();

    return this->timestamp != -1;
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
 * Show's the time
 * @return std::ostringstream
 */
std::ostringstream TS_CommandTimestamp::showTime()
{
    std::ostringstream timeInfo;
    timeInfo << "Current time: " << TS_Helper::formatTimestamp(this->timestamp);

    return timeInfo;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandTimestamp::getMessage()
{
    std::ostringstream message = this->showTime();

    if (this->timestamp == -1)
    {
        message.str("");
        message << "Error by getting current timestamp.";
    }

    return message;
}
