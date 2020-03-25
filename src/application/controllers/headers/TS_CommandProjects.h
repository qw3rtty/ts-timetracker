/**
 * TS-CommandProjects
 *
 * List all projects
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDPROJECTS_H
#define TS_TIMETRACKER_TS_COMMANDPROJECTS_H

#include "TS_IModel.h"
#include "TS_Command.h"
#include <string>
#include <map>
#include <vector>
#include <sstream>

class TS_CommandProjects : public TS_Command
{
public:
    explicit TS_CommandProjects(char *arguments, TS_IModel* model);
    ~TS_CommandProjects();
    bool execute() override;
    std::ostringstream getMessage() override;

protected:
    bool prepare() override;

private:
    char* projectKey;
    std::map<int, std::string> list;

    void setProjectList(std::map<int, std::string> list);
    void setProjectKey(char* project);
    void showProjects();
};


#endif //TS_TIMETRACKER_TS_COMMANDPROJECTS_H
