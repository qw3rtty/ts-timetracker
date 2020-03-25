/**
 * TS-CommandProjects
 *
 * List all projects
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <string>
#include <vector>

#include "TS_Helper.h"
#include "TS_IModel.h"
#include "TS_CommandProjects.h"

/**
 * @inherit
 */
TS_CommandProjects::TS_CommandProjects(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{
    this->projectKey = nullptr;
}

/**
 * Destructor
 */
TS_CommandProjects::~TS_CommandProjects()
{
    this->list.clear();
}

/**
 * @inherit
 */
bool TS_CommandProjects::execute()
{
    return this->prepare();
}

/**
 * @inherit
 */
bool TS_CommandProjects::prepare()
{
    this->setProjectKey(this->model->getSelectedProject());
    this->setProjectList(this->model->getProjectList());

    return true;
}

/**
 * Set given project list
 * @param   list    - Project list to set
 */
void TS_CommandProjects::setProjectList(std::map<int, std::string> list)
{
    this->list = std::move(list);
}

/**
 * Set given project key
 * @param   char*     - Project to set
 */
void TS_CommandProjects::setProjectKey(char* project)
{
    this->projectKey = project;
}

/**
 * Show all projects
 */
void TS_CommandProjects::showProjects()
{
    TS_Helper helper;
    auto listIterator = this->list.begin();
    while ( (listIterator != this->list.end()) )
    {
        std::cout << listIterator->first << " => " << listIterator->second;
        if (this->projectKey != nullptr && listIterator->second == this->projectKey)
        {
            std::cout << helper.color << " [selected]" << helper.noColor;
        }

        listIterator++;
        if (listIterator != this->list.end())
        {
            std::cout << std::endl;
        }
    }
}

/**
 * @inherit
 */
std::ostringstream TS_CommandProjects::getMessage()
{
    std::ostringstream message;
    this->showProjects();

    return message;
}
