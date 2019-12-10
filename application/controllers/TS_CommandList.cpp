/**
 * TS-CommandList
 *
 * List projects command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <string>
#include <cstring>
#include <map>

#include "TS_ConfigReader.h"
#include "TS_Helper.h"
#include "TS_Application.h"
#include "TS_CommandList.h"

/**
 * @inherit
 */
TS_CommandList::TS_CommandList(char *arguments) : TS_Command(arguments)
{
    this->projectKey = -1;
}

/**
 * @inherit
 */
bool TS_CommandList::execute()
{
    this->prepare();

    if (this->isTestMode)
    {
        return true;
    }

    if (this->arguments == nullptr)
    {
        std::cout << "You entered no argument!" << std::endl;
        return false;
    }

    if (strcmp(this->arguments, "projects") == 0)
    {
        this->showProjects();
    }

    if (strcmp(this->arguments, "config") == 0)
    {
        this->showConfig();
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandList::prepare()
{
    this->setProjectKey(application->getChoosedProject());
    this->setProjectList(application->getProjectList());

    return true;
}

/**
 * Set given project list
 * @param std::map<int, std::string> list
 */
void TS_CommandList::setProjectList(std::map<int, std::string> list)
{
    this->list = list;
}

/**
 * Set given project key
 * @param int key
 */
void TS_CommandList::setProjectKey(int key)
{
    this->projectKey = key;
}

/**
 * Show all projects
 */
void TS_CommandList::showProjects()
{
    TS_Helper helper;
    auto listIterator = this->list.begin();
    while ( (listIterator != this->list.end()) )
    {
    std::cout << listIterator->first << " => " << listIterator->second;

        if (listIterator->first == this->projectKey)
        {
            std::cout << helper.color << " [selected]" << helper.noColor;
        }

        std::cout << std::endl;
        listIterator++;
    }
}

/**
 * Show all settings in config
 */
void TS_CommandList::showConfig()
{
    TS_ConfigReader config;
    if (!config.configLoaded)
    {
        return;
    }

    if (!this->isTestMode)
    {
        config.showConfig();
    }
}