/**
 * TS-Application
 *
 * Singleton class for application managing.
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

#include "headers/TS_Application.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandHelp.h"
#include "./headers/TS_CommandList.h"
#include "./headers/TS_CommandShowConfig.h"
#include "./headers/TS_CommandTimestamp.h"

/**
 * Constructor
 */
TS_Application::TS_Application()
{
    this->choosedProject = -1;
    this->model.getProjectList();
}

/**
 * Getter for instance
 * @return TS_Application
 */
TS_Application *TS_Application::getInstance()
{
    static TS_Application *instance = new TS_Application();
    return instance;
}

/**
 * Set entered command with attributes of user
 * @param command
 */
void TS_Application::setCommandWithAttributes(char *command)
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
bool TS_Application::isCommandValid()
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
void TS_Application::runCommand()
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
        cmdList.setProjectKey(this->choosedProject);
        cmdList.setProjectList(this->model.getProjectList());
        cmdList.execute();
    }

    if (strcmp(this->command, "set") == 0)
    {
        this->choosedProject = atoi(this->arguments);
        if (this->choosedProject)
        {
            std::cout << "You choosed '" << this->model.getProjectName(this->choosedProject) << "'" << std::endl;
        }
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
    }

    if (strcmp(this->command, "save") == 0)
    {
        std::stringstream entryBuffer;
        entryBuffer << this->startTimestamp << ";" << this->endTimestamp;

        bool successfullySaved = this->model.save(entryBuffer.str(), this->choosedProject);
        if (successfullySaved)
        {
            std::cout << "Successfully saved new time track!" << std::endl;
        }
        else
        {
            std::cout << "Error on saving new time track! Try again ..." << std::endl;
        }
    }
}

/**
 * Unit test
 * @return bool
 */
bool TS_Application::unitTest()
{
    char command[100] = "help";
    TS_Application *applicationTest;
    applicationTest = this->getInstance();

    applicationTest->setCommandWithAttributes(command);
    return applicationTest->isCommandValid();
}