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

#include "TS_IModel.h"
#include <string>
#include <map>
#include <vector>

class TS_ModelFilesystem : public TS_IModel
{
public:
    TS_ModelFilesystem();
    ~TS_ModelFilesystem() override;

    void setProject(int key) override;

    std::vector<std::string> getTimes() override;
    std::string getName() override;
    std::map<int, std::string> getProjectList() override;

    bool save(const std::string& entry) override;
    void clearProjectListCache() override;

private:
    bool prepare();
    int selectedProjectKey;
    std::string projectsPath;
    std::map<int, std::string> projectList;
};


#endif //TS_TIMETRACKER_TS_MODELFILESYSTEM_H
