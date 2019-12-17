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

#include <cstdlib>
#include <cstring>
#include <string>
#include <map>

#include "TS_Application.h"

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
 * Get entered command
 * @return char *
 */
char* TS_Application::getCommand()
{
    return this->command;
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