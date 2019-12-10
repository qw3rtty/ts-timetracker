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

#ifndef TS_TIMETRACKER_TS_COMMANDLIST_H
#define TS_TIMETRACKER_TS_COMMANDLIST_H

#include "TS_Command.h"
#include <string>
#include <map>

class TS_CommandList : public TS_Command
{
public:
    explicit TS_CommandList(char *arguments);
    bool execute();

protected:
    bool prepare();

private:
    int projectKey;
    std::map<int, std::string> list;

    void setProjectList(std::map<int, std::string> list);
    void setProjectKey(int key);
    void showProjects();
    void showConfig();
};


#endif //TS_TIMETRACKER_TS_COMMANDLIST_H
