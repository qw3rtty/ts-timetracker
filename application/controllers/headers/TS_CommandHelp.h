/**
 * TS-CommandHelp
 *
 * Help command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDHELP_H
#define TS_TIMETRACKER_TS_COMMANDHELP_H

#include "TS_Command.h"

class TS_CommandHelp : public TS_Command
{
public:
    explicit TS_CommandHelp(char *arguments);
    bool execute() override;

protected:
    bool prepare() override;
};


#endif //TS_TIMETRACKER_TS_COMMANDHELP_H
