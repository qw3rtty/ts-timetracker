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

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <string>
#include <map>

#include "TS_Application.h"
#include "TS_CommandHelp.h"
#include "TS_CommandList.h"
#include "TS_CommandRemove.h"
#include "TS_CommandTimestampStart.h"
#include "TS_CommandTimestampStop.h"
#include "TS_CommandTouch.h"
#include "TS_CommandUse.h"

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
    static auto *instance = new TS_Application();
    return instance;
}

/**
 * Set entered command with attributes of user
 * @param input
 */
void TS_Application::setCommandWithAttributes(char *input)
{
    char *pointerToken = strtok(input, " ");

    this->command = (char *) malloc(strlen(pointerToken) + 1);
    strcpy(this->command, pointerToken);
    pointerToken = strtok(nullptr, " ");

    while ( (pointerToken != nullptr) )
    {
        this->arguments = (char *) malloc(strlen(pointerToken) + 1);
        strcpy(this->arguments, pointerToken);
        pointerToken = strtok(nullptr, " ");
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
 * Set choosed project
 */
void TS_Application::setChoosedProject(int projectNumber)
{
    this->choosedProject = projectNumber;
}

/**
 * Get choosed project by user
 * @return int
 */
int TS_Application::getChoosedProject()
{
    return this->choosedProject;
}

/**
 * Get command attributes from input
 * @return char *
 */
char* TS_Application::getCommandAttributes()
{
    return this->arguments;
}

/**
 * Get list of all available projects
 * @return std::map<int, std::string>
 */
std::map<int, std::string> TS_Application::getProjectList()
{
    return this->model.getProjectList();
}

/**
 * Execute correct command
 */
void TS_Application::runCommand()
{
    if (strcmp(this->command, "help") == 0)
    {
        TS_CommandHelp cmdHelp(application->getCommandAttributes());
        cmdHelp.execute();
    }

    if (strcmp(this->command, "touch") == 0)
    {
        TS_CommandTouch cmdTouch(application->getCommandAttributes());
        cmdTouch.execute();
    }

    if (strcmp(this->command, "rm") == 0)
    {
        TS_CommandRemove cmdRemove(application->getCommandAttributes());
        cmdRemove.execute();
    }

    if (strcmp(this->command, "ls") == 0)
    {
        TS_CommandList cmdList(application->getCommandAttributes());
        cmdList.execute();
    }

    if (strcmp(this->command, "use") == 0)
    {
        TS_CommandUse cmdUse(application->getCommandAttributes());
        cmdUse.execute();
    }

    if (strcmp(this->command, "start") == 0)
    {
        TS_CommandTimestampStart cmdTimestampStart(application->getCommandAttributes());
        cmdTimestampStart.execute();

        this->startTimestamp = cmdTimestampStart.getTimestamp();
    }

    if (strcmp(this->command, "stop") == 0)
    {
        TS_CommandTimestampStop cmdTimestampStop(application->getCommandAttributes());
        cmdTimestampStop.execute();

        this->endTimestamp = cmdTimestampStop.getTimestamp();
    }

    if (strcmp(this->command, "save") == 0)
    {
        if (this->choosedProject >= 0)
        {
            std::stringstream entryBuffer;
            entryBuffer << this->startTimestamp << ";" << this->endTimestamp;

            bool successfullySaved = this->model.save(entryBuffer.str());
            if (successfullySaved)
            {
                std::cout << "Successfully saved new time track!" << std::endl;
            }
            else
            {
                std::cout << "Error on saving new time track! Try again ..." << std::endl;
            }
        }
        else
        {
            std::cout << "You have to choose a project!" << std::endl;
            std::cout << "Type 'help' to get more informations." << std::endl;
        }
    }
}

/**
 * Clear project list cache
 */
void TS_Application::clearProjectList()
{
    this->model.clearProjectListCache();
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