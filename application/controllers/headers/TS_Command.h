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
    TS_Command();
    bool execute();

protected:
    bool prepare();
};


#endif //TS_TIMETRACKER_TS_COMMAND_H
