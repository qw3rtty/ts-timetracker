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
#include "./headers/TS_CommandDelegator.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandHelp.h"

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

    this->command = (char *)malloc(strlen(pointerToken) + 1);
    strcpy(this->command, pointerToken);
    pointerToken = strtok(NULL, " ");

    while(pointerToken != NULL)
    {
        this->arguments = (char *)malloc(strlen(pointerToken) + 1);
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