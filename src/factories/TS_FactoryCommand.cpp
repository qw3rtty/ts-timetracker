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

#include "headers/TS_FactoryCommand.h"
#include "TS_IModel.h"
#include "TS_CommandExport.h"
#include "TS_CommandHelp.h"
#include "TS_CommandList.h"
#include "TS_CommandConfig.h"
#include "TS_CommandProjects.h"
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

/**
 * Factory for commands
 * @param   command     - Entered command by user
 * @param   arguments   - Entered arguments by user
 * @param   model       - Configured model
 * @return  TS_Command  - Command instance of needed command
 */
TS_Command* TS_FactoryCommand::build(char *command, char *arguments, TS_IModel* model)
{
    TS_Command *cmd;
    if (strcmp(command, "help") == 0)
    {
        cmd = new TS_CommandHelp(arguments, model);
    }
    else if (strcmp(command, "touch") == 0)
    {
        cmd = new TS_CommandTouch(arguments, model);
    }
    else if (strcmp(command, "rm") == 0)
    {
        cmd = new TS_CommandRemove(arguments, model);
    }
    else if (strcmp(command, "ls") == 0)
    {
        cmd = new TS_CommandList(arguments, model);
    }
    else if (strcmp(command, "config") == 0)
    {
        cmd = new TS_CommandConfig(arguments, model);
    }
    else if (strcmp(command, "projects") == 0)
    {
        cmd = new TS_CommandProjects(arguments, model);
    }
    else if (strcmp(command, "use") == 0)
    {
        cmd = new TS_CommandUse(arguments, model);
    }
    else if (strcmp(command, "start") == 0)
    {
        cmd = new TS_CommandTimestampStart(arguments, model);
    }
    else if (strcmp(command, "stop") == 0)
    {
        cmd = new TS_CommandTimestampStop(arguments, model);
    }
    else if (strcmp(command, "save") == 0)
    {
        cmd = new TS_CommandSave(arguments, model);
    }
    else if (strcmp(command, "export") == 0)
    {
        cmd = new TS_CommandExport(arguments, model);
    }
    else
    {
        cmd = new TS_CommandHelp(arguments, model);
    }

    return cmd;
}