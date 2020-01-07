/**
 * TS-CommandTouch
 *
 * Create a new project
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDTOUCH_H
#define TS_TIMETRACKER_TS_COMMANDTOUCH_H

#include <string>
#include <sstream>
#include "TS_Command.h"

class TS_CommandTouch : public TS_Command
{
public:
    explicit TS_CommandTouch(char *arguments);
    bool execute() override;
    std::ostringstream getMessage() override;

protected:
    bool prepare() override;

private:
    bool touchedSuccessful;
    std::string storePath;
};


#endif //TS_TIMETRACKER_TS_COMMANDTOUCH_H
