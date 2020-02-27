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
#include "TS_IModel.h"
#include "TS_CommandList.h"
#include "../../libaries/VariadicTable.h"

/**
 * @inherit
 */
TS_CommandList::TS_CommandList(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{
    this->projectKey = nullptr;
}

/**
 * Destructor
 */
TS_CommandList::~TS_CommandList()
{
    this->list.clear();
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

    return this->arguments != nullptr;
}

/**
 * @inherit
 */
bool TS_CommandList::prepare()
{
    this->setProjectKey(this->model->getSelectedProject());
    this->setProjectList(this->model->getProjectList());

    return true;
}

/**
 * Set given project list
 * @param   list    - Project list to set
 */
void TS_CommandList::setProjectList(std::map<int, std::string> list)
{
    this->list = std::move(list);
}

/**
 * Set given project key
 * @param   char*     - Project to set
 */
void TS_CommandList::setProjectKey(char* project)
{
    this->projectKey = project;
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
    if (this->projectKey != nullptr)
    {
        this->printTimeTable();
        this->printTrackedTimeAmount();
    }
    else
    {
        std::cout << "You have to choose a project!" << std::endl;
        std::cout << "Type 'help' to get more informations.";
    }
}

/**
 * Prints the time table
 */
void TS_CommandList::printTimeTable()
{
    VariadicTable<std::string, std::string, std::string> table({
        "Start time", "End time", "Comment"
    });

    auto times = this->model->getTimes();
    for (auto const& entry: times)
    {
        std::vector<std::string> row;
        std::string token;
        std::stringstream stream(entry);
        char delimiter = ';';

        while (std::getline(stream, token, delimiter))
        {
            row.push_back(token);
        }

        std::time_t startTime = std::stoi(row.at(1));
        std::time_t stopTime = std::stoi(row.at(0));

        std::string test[3] = {
            row.at(2),
            TS_Helper::formatTimestamp(startTime),
            TS_Helper::formatTimestamp(stopTime),
        };

        // TODO: TS - find a better way here
        table.addRow(
            reinterpret_cast<const std::tuple<std::basic_string<char>, std::basic_string<char>, std::basic_string<char>> &>(test)
        );
    }

    table.print(std::cout);
}

/**
 * Print the complete amount of tracked times
 */
void TS_CommandList::printTrackedTimeAmount()
{
    std::cout << "Tracked time amount: " << std::fixed << std::setprecision(2)
        << this->model->getTimeAmount() << "h" << std::endl;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandList::getMessage()
{
    std::ostringstream message;

    if (this->arguments == nullptr)
    {
        message << "You entered no argument!";
    }
    else if (strcmp(this->arguments, "projects") == 0)
    {
        this->showProjects();
    }
    else if (strcmp(this->arguments, "config") == 0)
    {
        this->showConfig();
    }
    else if (strcmp(this->arguments, "times") == 0)
    {
        this->showTimes();
    }
    else
    {
        message << "You entered an invalid argument!";
    }

    return message;
}
