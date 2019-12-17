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

#include "TS_ModelFilesystem.h"
#include "TS_ConfigReader.h"

#include <string>
#include <map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <sstream>

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
    if (!this->projectList.empty())
    {
        return this->projectList;
    }

    DIR *directory;
    struct dirent *entry;
    unsigned int counter = 0;

    directory = opendir(this->projectsPath.c_str());
    if (directory)
    {
        while ( (entry = readdir(directory)) )
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
    for (auto & it : this->projectList)
    {
        if (it.first == this->selectedProjectKey)
        {
            return it.second;
        }
    }

    return "";
}

/**
 * Saves new entry to file
 * @param std::string entry
 * @return bool
 */
bool TS_ModelFilesystem::save(const std::string& entry)
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
 * Clear project list cache
 */
void TS_ModelFilesystem::clearProjectListCache()
{
    this->projectList.clear();
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

/**
 * Get all entries of current project
 * @return std::vector<std::string>
 */
std::vector<std::string> TS_ModelFilesystem::getProjectTimes()
{
    std::vector<std::string> entries;
    std::string line;
    std::string projectName = this->getProjectName();
    std::stringstream pathToProjectFile;

    pathToProjectFile << this->projectsPath << projectName;
    std::ifstream projectFile(pathToProjectFile.str());

    while (std::getline(projectFile, line))
    {
        if (!line.empty())
        {
            entries.push_back(line);
        }
    }
    projectFile.close();

    return entries;
}
