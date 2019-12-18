/**
 * TS-CommandTimestampStart
 *
 * Creates current start timestamp
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>

#include "TS_Application.h"
#include "TS_CommandTimestamp.h"
#include "TS_CommandTimestampStart.h"

/**
 * @inherit
 */
TS_CommandTimestampStart::TS_CommandTimestampStart(char *arguments) : TS_CommandTimestamp(arguments)
{}

/**
 * @inherit
 */
void TS_CommandTimestampStart::showTime()
{
    std::cout << "Time tracking has started." << std::endl;
    std::cout << "Starting time: " << this->getFormattedDate() << std::endl;
}

/**
 * @inherit
 */
bool TS_CommandTimestampStart::execute()
{
    TS_CommandTimestamp::execute();

    application->startTimestamp = this->getTimestamp();

    return true;
}