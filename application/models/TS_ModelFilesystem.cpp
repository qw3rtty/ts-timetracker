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
#include "TS_Helper.h"

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
 * Destructor
 */
TS_ModelFilesystem::~TS_ModelFilesystem()
{
    this->projectList.clear();
}

/**
 * Set given project key
 * @param   key     - Project key of selected one to set
 */
void TS_ModelFilesystem::setProject(int key)
{
    this->selectedProjectKey = key;
}

/**
 * Get projects list
 * @return  std::map<int, std::string>  - List of all available projects
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
 * @return  std::string     - Project name of selected one
 */
std::string TS_ModelFilesystem::getName()
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
 * @param   entry   - Entry to save
 * @return  bool    - true if saving was successful, false else
 */
bool TS_ModelFilesystem::save(const std::string& entry)
{
    std::string file = this->projectsPath;
    file.append(this->getName());

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
 * @return  bool
 */
bool TS_ModelFilesystem::prepare()
{
    this->projectsPath = TS_Helper::getProjectsPath();

    return true;
}

/**
 * Get all entries of current project
 * @return  std::vector<std::string>     - All tracked times of selected project
 */
std::vector<std::string> TS_ModelFilesystem::getTimes()
{
    std::vector<std::string> entries;
    std::string line;
    std::string projectName = this->getName();
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
