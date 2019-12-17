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
#include <vector>
#include <map>
#include <utility>

#include "TS_ConfigReader.h"
#include "TS_Helper.h"
#include "TS_Application.h"
#include "TS_CommandList.h"
#include "../../libaries/VariadicTable.h"

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

    if (strcmp(this->arguments, "times") == 0)
    {
        this->showTimes();
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
    this->list = std::move(list);
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

/**
 * Show all tracked times
 */
void TS_CommandList::showTimes()
{
    if (this->projectKey >= 0)
    {
        this->printTimeTable(application->model.getProjectTimes());
    }
    else
    {
        std::cout << "You have to choose a project!" << std::endl;
        std::cout << "Type 'help' to get more informations." << std::endl;
    }
}

/**
 * Prints the time table
 * @param std::vector<std::string>  times
 */
void TS_CommandList::printTimeTable(std::vector<std::string> times)
{
    VariadicTable<std::string, std::string, std::string> table({
        "Start time", "End time", "Comment"
    });

    for (auto const& entry: times)
    {
        std::vector<std::string> row;
        std::string token;
        std::stringstream stream(entry);
        char delimeter = ';';

        while (std::getline(stream, token, delimeter))
        {
            row.push_back(token);
        }

        // TODO: find a better way here!!
        //  Format dates to format of config
        std::string test[3] = {row.at(2), row.at(1), row.at(0)};
        table.addRow(
            reinterpret_cast<const std::tuple<std::basic_string<char>, std::basic_string<char>, std::basic_string<char>> &>(test)
        );
    }

    table.print(std::cout);
}
