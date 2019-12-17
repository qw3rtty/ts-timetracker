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

#ifndef TS_TIMETRACKER_TS_COMMANDTIMESTAMPSTOP_H
#define TS_TIMETRACKER_TS_COMMANDTIMESTAMPSTOP_H

#include <ctime>
#include "TS_CommandTimestamp.h"

class TS_CommandTimestampStop : public TS_CommandTimestamp
{
public:
    explicit TS_CommandTimestampStop(char *arguments);
    bool execute() override;

private:
    void showTime() override;
};


#endif //TS_TIMETRACKER_TS_COMMANDTIMESTAMPSTOP_H
