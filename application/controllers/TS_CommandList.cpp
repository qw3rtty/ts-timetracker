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
#include <map>
#include <iterator>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>

#include "../../config/TS_ConfigReader.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandList.h"

/**
 * @inherit
 */
TS_CommandList::TS_CommandList()
{
    this->isTestMode = false;
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

    std::map<int, std::string>::iterator listIterator = this->list.begin();
    while (listIterator != this->list.end())
    {
        std::cout << listIterator->first << " => " << listIterator->second << std::endl;
        listIterator++;
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandList::prepare()
{
    TS_ConfigReader config;
    std::string projectsPath = config.getConfigEntry("projectsPath");

    DIR *directory;
    struct dirent *entry;
    unsigned int counter = 0;
    if (directory = opendir(projectsPath.c_str()))
    {
        while (entry = readdir(directory))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 )
            {
                continue;
            }
            this->list.insert(std::make_pair(counter++, entry->d_name));
        }
        closedir(directory);
    }

    return true;
}

/**
 * Set test mode
 * @param testMode
 */
void TS_CommandList::setTestMode(bool testMode)
{
    this->isTestMode = testMode;
}