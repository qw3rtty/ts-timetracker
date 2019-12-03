#ifndef TS_TIMETRACKER_TS_APPLICATION_H
#define TS_TIMETRACKER_TS_APPLICATION_H

/**
 * TS-Application
 *
 * Singleton class for application managing.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <stdio.h>
#include <ctime>
#include <string>
#include <map>

#include "TS_Base.h"
#include "TS_Command.h"
#include "../../models/headers/TS_ModelFilesystem.h"

class TS_Application : public TS_Base
{
private:
    TS_Application();
    const char commandList[8][15] = {"help", "showConfig", "ls", "use", "start", "stop", "save"};
    char *arguments;
    char *command;
    int choosedProject;
    std::time_t startTimestamp;
    std::time_t endTimestamp;
    TS_ModelFilesystem model;

public:
    static TS_Application *getInstance();
    void setCommandWithAttributes(char *command);
    bool isCommandValid();
    void runCommand();
    int getChoosedProject();
    std::map<int, std::string> getProjectList();

    bool unitTest();
};

#define application TS_Application::getInstance()
#endif //TS_TIMETRACKER_TS_APPLICATION_H