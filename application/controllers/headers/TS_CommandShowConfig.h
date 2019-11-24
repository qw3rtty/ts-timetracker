/**
 * TS-CommandShowConfig
 *
 * Shows loaded config entries
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDSHOWCONFIG_H
#define TS_TIMETRACKER_TS_COMMANDSHOWCONFIG_H

#include "TS_Command.h"

class TS_CommandShowConfig : public TS_Command
{
public:
    TS_CommandShowConfig();
    bool execute();
    void setTestMode(bool testMode);

protected:
    bool prepare();

private:
    bool isTestMode;
};


#endif //TS_TIMETRACKER_TS_COMMANDSHOWCONFIG_H
