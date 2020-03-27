/**
 * TS-CommandTimes
 *
 * List tracked times
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
#include <vector>
#include <map>

#include "TS_Helper.h"
#include "TS_IModel.h"
#include "TS_CommandTimes.h"
#include "../../libaries/VariadicTable.h"

/**
 * @inherit
 */
TS_CommandTimes::TS_CommandTimes(char *arguments, TS_IModel* model) : TS_Command(arguments, model)
{}

/**
 * Destructor
 */
TS_CommandTimes::~TS_CommandTimes()
{}

/**
 * @inherit
 */
bool TS_CommandTimes::execute()
{
    return this->prepare();
}

/**
 * @inherit
 */
bool TS_CommandTimes::prepare()
{
    this->setProjectKey(this->model->getSelectedProject());

    return true;
}

/**
 * Set given project key
 * @param   char*     - Project to set
 */
void TS_CommandTimes::setProjectKey(char* project)
{
    this->projectKey = project;
}

/**
 * Show all tracked times
 */
void TS_CommandTimes::showTimes()
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
void TS_CommandTimes::printTimeTable()
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
void TS_CommandTimes::printTrackedTimeAmount()
{
    std::cout << "Tracked time amount: " << std::fixed << std::setprecision(2)
        << this->model->getTimeAmount() << "h" << std::endl;
}

/**
 * @inherit
 */
std::ostringstream TS_CommandTimes::getMessage()
{
    std::ostringstream message;
    this->showTimes();

    return message;
}
