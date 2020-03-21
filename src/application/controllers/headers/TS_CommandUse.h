/**
 * TS-CommandUse
 *
 * Select project command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDUSE_H
#define TS_TIMETRACKER_TS_COMMANDUSE_H

#include <sstream>
#include "TS_IModel.h"
#include "TS_Command.h"

class TS_CommandUse : public TS_Command
{
public:
    explicit TS_CommandUse(char *arguments, TS_IModel* model);
    ~TS_CommandUse() = default;
    bool execute() override;
    std::ostringstream getMessage() override;

protected:
    bool prepare() override;
};


#endif //TS_TIMETRACKER_TS_COMMANDUSE_H
