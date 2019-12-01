/**
 * TS-ModelFilesystem
 *
 * Model for filesystem storage.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include "headers/TS_ModelFilesystem.h"
#include "../../config/TS_ConfigReader.h"
#include <string>
#include <map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>

/**
 * Constructor
 */
TS_ModelFilesystem::TS_ModelFilesystem()
{
    this->selectedProjectKey = -1;
    this->prepare();
}

/**
 * Set given project key
 * @param key
 */
void TS_ModelFilesystem::setSelectedProjectKey(int key)
{
    this->selectedProjectKey = key;
}

/**
 * Get projects list
 * @return std::map<int, std::string>
 */
std::map<int, std::string> TS_ModelFilesystem::getProjectList()
{
    if (this->projectList.size() > 0)
    {
        return this->projectList;
    }

    DIR *directory;
    struct dirent *entry;
    unsigned int counter = 0;
    if (directory = opendir(this->projectsPath.c_str()))
    {
        while (entry = readdir(directory))
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 )
            {
                continue;
            }
            this->projectList.insert(std::make_pair(counter++, entry->d_name));
        }
        closedir(directory);
    }

    return this->projectList;
}

/**
 * Get project by given key
 * @return std::string
 */
std::string TS_ModelFilesystem::getProjectName()
{
    for (auto it = this->projectList.begin(); it != this->projectList.end(); ++it)
    {
        if (it->first == this->selectedProjectKey)
        {
            return it->second;
        }
    }

    return "";
}

/**
 * Saves new entry to file
 * @param std::string entry
 * @return bool
 */
bool TS_ModelFilesystem::save(std::string entry)
{
    std::string file = this->projectsPath;
    file.append(this->getProjectName());

    std::ofstream project(file, std::ios_base::app);
    if (project.is_open())
    {
        project << entry << std::endl;
        project.close();
        return true;
    }

    return false;
}

/**
 * Prepare model
 * @return
 */
bool TS_ModelFilesystem::prepare()
{
    TS_ConfigReader configReader;
    this->projectsPath = configReader.getConfigEntry("projectsPath");

    return true;
}