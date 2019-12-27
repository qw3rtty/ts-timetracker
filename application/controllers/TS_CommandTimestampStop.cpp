/**
 * TS-CommandTimestampStop
 *
 * Creates current stop timestamp
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>

#include "TS_Helper.h"
#include "TS_Application.h"
#include "TS_CommandTimestamp.h"
#include "TS_CommandTimestampStop.h"

/**
 * @inherit
 */
TS_CommandTimestampStop::TS_CommandTimestampStop(char *arguments) : TS_CommandTimestamp(arguments)
{}

/**
 * @inherit
 */
void TS_CommandTimestampStop::showTime()
{
    std::cout << "Time tracking finished." << std::endl;
    std::cout << "Finished time: " << TS_Helper::formatTimestamp(this->timestamp) << std::endl;
}

/**
 * @inherit
 */
bool TS_CommandTimestampStop::execute()
{
    TS_CommandTimestamp::execute();

    application->endTimestamp = this->getTimestamp();

    return true;
}