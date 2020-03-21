/**
 * TS-CommandConfig
 *
 * List config options
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDCONFIG_H
#define TS_TIMETRACKER_TS_COMMANDCONFIG_H

#include "TS_IModel.h"
#include "TS_Command.h"
#include "TS_ConfigReader.h"
#include <string>
#include <map>
#include <vector>
#include <sstream>

class TS_CommandConfig : public TS_Command
{
public:
    explicit TS_CommandConfig(char *arguments, TS_IModel* model);
    ~TS_CommandConfig();
    bool execute() override;
    std::ostringstream getMessage() override;

protected:
    bool prepare() override;

private:
    TS_ConfigReader *configReader;
    void showConfig();
};


#endif //TS_TIMETRACKER_TS_COMMANDCONFIG_H
