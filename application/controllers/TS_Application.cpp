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

#include <cstring>
#include <string>
#include <map>

#include "TS_Application.h"

/**
 * Constructor
 */
TS_Application::TS_Application()
{
    this->command = {};
    this->arguments = {};
    this->choosedProject = -1;
    this->model.getProjectList();
}

/**
 * Destructor
 */
TS_Application::~TS_Application()
{
    delete this->command;
    delete this->arguments;
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
 * @param   input   - User input
 */
void TS_Application::setCommandWithAttributes(char *input)
{
    this->resetPointers();
    char *pointerToken = strtok(input, " ");

    this->command = (char *) malloc(strlen(pointerToken) + 1);
    strcpy(this->command, pointerToken);
    pointerToken = strtok(nullptr, "");

    while ( (pointerToken != nullptr) )
    {
        this->arguments = (char *) malloc(strlen(pointerToken) + 1);
        this->arguments = strcpy(this->arguments, pointerToken);
        pointerToken = strtok(nullptr, "");
    }
}

/**
 * Check if entered command is valid
 * @return      bool    - true if command is valid, false else
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
 * @return  int - Choosed project number
 */
int TS_Application::getChoosedProject()
{
    return this->choosedProject;
}

/**
 * Get list of all available projects
 * @return  std::map<int, std::string>  - Project list
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
 * Get selected project name
 * @return  std::string
 */
std::string TS_Application::getSelectedProjectName()
{
    return this->model.getName();
}


/**
 * Reset command and arguments pointer
 */
void TS_Application::resetPointers()
{
    this->command = nullptr;
    this->arguments = nullptr;
}

/**
 * Get entered command
 * @return  char*   - The command
 */
char *TS_Application::getCommand()
{
    return this->command;
}

/**
 * Get entered arguments
 * @return  char*   - The arguments
 */
char *TS_Application::getArguments()
{
    return this->arguments;
}
