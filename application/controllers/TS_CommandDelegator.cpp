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
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <ctime>

#include "./headers/TS_CommandDelegator.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandHelp.h"
#include "./headers/TS_CommandList.h"
#include "./headers/TS_CommandShowConfig.h"
#include "./headers/TS_CommandTimestamp.h"

/**
 * Constructor
 */
TS_CommandDelegator::TS_CommandDelegator()
{}

/**
 * Getter for instance
 * @return TS_CommandDelegator
 */
TS_CommandDelegator *TS_CommandDelegator::getInstance()
{
    static TS_CommandDelegator *instance = new TS_CommandDelegator();
    return instance;
}

/**
 * Set entered command with attributes of user
 * @param command
 */
void TS_CommandDelegator::setCommandWithAttributes(char *command)
{
    char *pointerToken = strtok(command, " ");

    this->command = (char *) malloc(strlen(pointerToken) + 1);
    strcpy(this->command, pointerToken);
    pointerToken = strtok(NULL, " ");

    while (pointerToken != NULL)
    {
        this->arguments = (char *) malloc(strlen(pointerToken) + 1);
        strcpy(this->arguments, pointerToken);
        pointerToken = strtok(NULL, " ");
    }
}

/**
 * Check if entered command is valid
 * @return bool
 */
bool TS_CommandDelegator::isCommandValid()
{
    bool correctCommand = false;
    int size = sizeof(this->commandList) / sizeof(this->commandList[0]);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(this->commandList[i], this->command) == 0)
        {
            correctCommand = true;
        }
    }

    return correctCommand;
}

/**
 * Execute correct command
 */
void TS_CommandDelegator::runCommand()
{
    if (strcmp(this->command, "help") == 0)
    {
        TS_CommandHelp cmdHelp;
        cmdHelp.execute();
    }

    if (strcmp(this->command, "showConfig") == 0)
    {
        TS_CommandShowConfig cmdConfig;
        cmdConfig.execute();
    }

    if (strcmp(this->command, "list") == 0)
    {
        TS_CommandList cmdList;
        cmdList.execute();
    }

    if (strcmp(this->command, "start") == 0)
    {
        TS_CommandTimestamp cmdTimestamp;
        cmdTimestamp.execute();

        this->startTimestamp = cmdTimestamp.getTimestamp();
        std::cout << "Time tracking has started." << std::endl;
        std::cout << "Starting time: " << cmdTimestamp.getFormattedDate() << std::endl;
    }

    if (strcmp(this->command, "stop") == 0)
    {
        TS_CommandTimestamp cmdTimestamp;
        cmdTimestamp.execute();

        this->endTimestamp = cmdTimestamp.getTimestamp();
        std::cout << "Time tracking finished." << std::endl;
        std::cout << "Finished time: " << cmdTimestamp.getFormattedDate() << std::endl;

        // TODO: create own command to save new timetrack & create better format for an entry
        std::stringstream entryBuffer;
        entryBuffer << "New timetrack: " << this->startTimestamp << " - " << this->endTimestamp;
        this->model.save(entryBuffer.str());
    }
}

/**
 * Unit test
 * @return bool
 */
bool TS_CommandDelegator::unitTest()
{
    char command[100] = "help";
    TS_CommandDelegator *delegator;
    delegator = this->getInstance();

    delegator->setCommandWithAttributes(command);
    return delegator->isCommandValid();
}