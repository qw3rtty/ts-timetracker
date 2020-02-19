/**
 * TS-UnitTest Command Timestamp
 *
 * Unit test for the Timestamp command.
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

#include "TS_Helper.h"
#include "TS_CommandTimestamp.h"
#include "TS_CommandTimestampStart.h"
#include "TS_CommandTimestampStop.h"

int main()
{
    TS_CommandTimestamp* timestamp = new TS_CommandTimestamp(nullptr);
    assert(timestamp->execute());
    std::cout << "TS_CommandTimestamp passed" << " \u2713" << std::endl;

    TS_CommandTimestampStart* timestampStart = new TS_CommandTimestampStart(nullptr);
    assert(timestampStart->execute());
    std::cout << "TS_CommandTimestampStart passed" << " \u2713" << std::endl;

    TS_CommandTimestampStop* timestampStop = new TS_CommandTimestampStop(nullptr);
    assert(timestampStop->execute());
    std::cout << "TS_CommandTimestampStop passed" << " \u2713" << std::endl;

    return 0;
}
