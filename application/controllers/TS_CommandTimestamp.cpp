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
 * Show's the time
 */
void TS_CommandTimestamp::showTime()
{
    std::cout << "Current time: " << TS_Helper::formatTimestamp(this->timestamp) << std::endl;
}