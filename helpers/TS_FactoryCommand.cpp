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

#include <cstring>

#include "TS_FactoryCommand.h"
#include "TS_CommandHelp.h"
#include "TS_CommandList.h"
#include "TS_CommandRemove.h"
#include "TS_CommandSave.h"
#include "TS_CommandTimestampStart.h"
#include "TS_CommandTimestampStop.h"
#include "TS_CommandTouch.h"
#include "TS_CommandUse.h"

/**
 * Constructor
 */
TS_FactoryCommand::TS_FactoryCommand() = default;

TS_Command* TS_FactoryCommand::build(char *command, char *arguments)
{
    TS_Command *cmd;
    if (strcmp(command, "help") == 0)
    {
        cmd = new TS_CommandHelp(arguments);
    }
    else if (strcmp(command, "touch") == 0)
    {
        cmd = new TS_CommandTouch(arguments);
    }
    else if (strcmp(command, "rm") == 0)
    {
        cmd = new TS_CommandRemove(arguments);
    }
    else if (strcmp(command, "ls") == 0)
    {
        cmd = new TS_CommandList(arguments);
    }
    else if (strcmp(command, "use") == 0)
    {
        cmd = new TS_CommandUse(arguments);
    }
    else if (strcmp(command, "start") == 0)
    {
        cmd = new TS_CommandTimestampStart(arguments);
    }
    else if (strcmp(command, "stop") == 0)
    {
        cmd = new TS_CommandTimestampStop(arguments);
    }
    else if (strcmp(command, "save") == 0)
    {
        cmd = new TS_CommandSave(arguments);
    }
    else
    {
        cmd = new TS_CommandHelp(arguments);
    }

    return cmd;
}