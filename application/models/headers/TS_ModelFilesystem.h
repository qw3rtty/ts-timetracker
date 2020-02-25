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

    void setProject(char* project) override;

    std::vector<std::string> getTimes() override;
    float getTimeAmount() override;
    std::string getName() override;
    std::map<int, std::string> getProjectList() override;

    bool save(const std::string& entry) override;
    void clearProjectListCache() override;

protected:
    bool reset() override;
    void loadProjectList() override;
    float convertAmountToHours() override;

private:
    bool prepare();
    char* selectedProjectKey = nullptr;
    std::string projectsPath = "";
    std::map<int, std::string> projectList;
};


#endif //TS_TIMETRACKER_TS_MODELFILESYSTEM_H
