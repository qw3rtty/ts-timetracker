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
#include "TS_IModel.h"
#include "TS_CommandTimestamp.h"
#include "TS_CommandTimestampStop.h"

/**
 * @inherit
 */
TS_CommandTimestampStop::TS_CommandTimestampStop(char *arguments, TS_IModel* model)
: TS_CommandTimestamp(arguments, model)
{}

/**
 * @inherit
 */
std::ostringstream TS_CommandTimestampStop::showTime()
{
    std::ostringstream timeInfo;
    timeInfo << "Time tracking finished." << std::endl;
    timeInfo << "Finished time: " << TS_Helper::formatTimestamp(this->timestamp);

    return timeInfo;
}

/**
 * @inherit
 */
bool TS_CommandTimestampStop::execute()
{
    TS_CommandTimestamp::execute();

    this->model->endTimestamp = this->getTimestamp();

    return true;
}