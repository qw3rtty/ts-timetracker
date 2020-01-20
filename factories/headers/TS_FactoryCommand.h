/**
 * TS-FactoryCommand
 *
 * Factory class for command building.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_FACTORYCOMMAND_H
#define TS_TIMETRACKER_TS_FACTORYCOMMAND_H

#include "TS_Command.h"

class TS_FactoryCommand
{
public:
    TS_FactoryCommand();
    ~TS_FactoryCommand() = default;
    static TS_Command* build(char *command, char *arguments);
};

#endif //TS_TIMETRACKER_TS_HELPER_H
