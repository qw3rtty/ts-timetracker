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

#ifndef TS_TIMETRACKER_TS_MODELFILESYSTEM_H
#define TS_TIMETRACKER_TS_MODELFILESYSTEM_H

#include "TS_Model.h"
#include <string>
#include <map>
#include <vector>

class TS_ModelFilesystem : public TS_Model
{
public:
    TS_ModelFilesystem();
    void setSelectedProjectKey(int key);
    std::map<int, std::string> getProjectList();
    std::string getProjectName();
    bool save(const std::string& entry);
    void clearProjectListCache();
    std::vector<std::string> getProjectTimes();

private:
    bool prepare();
    int selectedProjectKey;
    std::string projectsPath;
    std::map<int, std::string> projectList;
};


#endif //TS_TIMETRACKER_TS_MODELFILESYSTEM_H
