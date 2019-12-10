/**
 * TS-ConfigReader
 *
 * Config reader class.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include "TS_ConfigReader.h"

#include <iostream>
#include <fstream>
#include <string>

/**
 * Constructor
 */
TS_ConfigReader::TS_ConfigReader()
{
    this->filename = "/home/tom/development/ts-timetracker/.ts-timetracker.conf";
    this->configLoaded = this->loadConfig();
}

/**
 * Show loaded config
 */
void TS_ConfigReader::showConfig()
{
    if (!this->configLoaded)
    {
        std::cout << "No config loaded yet!" << std::endl;
        return;
    }

    auto configIterator = this->entries.begin();
    while ( (configIterator != this->entries.end()) )
    {
        std::cout << configIterator->first << " => " << configIterator->second << std::endl;
        configIterator++;
    }
}

/**
 * Return's value of given config entry
 * @param entry
 * @return std::string
 */
std::string TS_ConfigReader::getConfigEntry(const std::string& entry)
{
    for (auto & entrie : this->entries)
    {
        if (entrie.first == entry)
        {
            return entrie.second;
        }
    }

    return "";
}

/**
 * Load config file
 * @return  bool
 */
bool TS_ConfigReader::loadConfig()
{
    std::ifstream file;
    std::string line;

    std::string delimiter = "=";
    std::string key;
    std::string value;

    file.open(this->filename);
    if (!file.is_open())
    {
        std::cout << "Could not load config file!" << std::endl;
        return false;
    }

    while (!file.eof())
    {
        getline(file, line);

        key = line.substr(0, line.find(delimiter));
        value = line.substr(line.find(delimiter) + 1, line.length());

        this->entries.insert(std::make_pair(key, value));
    }
    file.close();

    return true;
}