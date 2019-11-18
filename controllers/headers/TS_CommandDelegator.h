#ifndef TS_TIMETRACKER_TS_COMMANDDELEGATOR_H
#define TS_TIMETRACKER_TS_COMMANDDELEGATOR_H

/**
 * TS-CommandDelegator
 *
 * Singleton class for managing commands
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <stdio.h>
#include "TS_Base.h"

class TS_CommandDelegator : public TS_Base
{
private:
    TS_CommandDelegator();
    const char commandList[1][10] = {"help"};
    char *command;

public:
    static TS_CommandDelegator *getInstance();
    void setCommand(char * command);
    bool isCommandValid();
};

#define commandDelegator TS_CommandDelegator::getInstance()
#endif //TS_TIMETRACKER_TS_COMMANDDELEGATOR_H