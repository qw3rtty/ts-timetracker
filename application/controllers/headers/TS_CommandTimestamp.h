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

#ifndef TS_TIMETRACKER_TS_COMMANDTIMESTAMP_H
#define TS_TIMETRACKER_TS_COMMANDTIMESTAMP_H

#include <ctime>
#include "TS_Command.h"

class TS_CommandTimestamp : public TS_Command
{
public:
    explicit TS_CommandTimestamp(char *arguments);
    bool execute() override;
    std::time_t getTimestamp();

protected:
    bool prepare() override;
    std::time_t timestamp{};

private:
    virtual void showTime();
};


#endif //TS_TIMETRACKER_TS_COMMANDTIMESTAMP_H
