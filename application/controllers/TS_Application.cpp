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
#include "TS_FactoryCommand.h"
#include "TS_FactoryView.h"

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
 * Build's the necessary command
 * @return  TS_Command      - Needed command for execution
 */
TS_Command* TS_Application::buildCommand()
{
    return TS_FactoryCommand::build(this->command, this->arguments);
}

/**
 * Build's the necessary view
 * @return  TS_View      - Needed view for execution
 */
TS_View* TS_Application::buildView()
{
    return TS_FactoryView::build();
}

/**
 * Set entered command with attributes of user
 * @param   input   - User input
 */
void TS_Application::setCommandWithAttributes(char *input)
{
    // Reset command and arguments
    this->command = nullptr;
    this->arguments = nullptr;

    char *pointerToken = strtok(input, " ");

    this->command = new char(strlen(pointerToken) + 1);
    strcpy(this->command, pointerToken);
    pointerToken = strtok(nullptr, "");

    while ( (pointerToken != nullptr) )
    {
        this->arguments = new char(strlen(pointerToken) + 1);
        strcpy(this->arguments, pointerToken);
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
 * Unit test
 * @return  bool    - true is test was successful, false else
 */
bool TS_Application::unitTest()
{
    char command[100] = "help";
    TS_Application *applicationTest;
    applicationTest = this->getInstance();

    applicationTest->setCommandWithAttributes(command);
    return applicationTest->isCommandValid();
}