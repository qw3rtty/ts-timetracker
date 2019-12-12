/**
 * TS-Command
 *
 * Abstract superclass for all commands
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMAND_H
#define TS_TIMETRACKER_TS_COMMAND_H

class TS_Command
{
public:
    explicit TS_Command(char *arguments);
    void setTestMode(bool testMode);
    virtual bool execute();

protected:
    virtual bool prepare();
    char *arguments;
    bool isTestMode;
};


#endif //TS_TIMETRACKER_TS_COMMAND_H
