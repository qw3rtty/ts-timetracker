/**
 * TS-CommandExport
 *
 * Export command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_COMMANDEXPORT_H
#define TS_TIMETRACKER_TS_COMMANDEXPORT_H

#include <string>
#include <sstream>
#include "TS_Command.h"

class TS_CommandExport : public TS_Command
{
public:
    explicit TS_CommandExport(char *arguments);
    bool execute() override;
    std::ostringstream getMessage() override;

protected:
    bool prepare() override;

private:
    std::string createCsvHeadline();
    std::string getExportPath();
    std::string getSelectedProjectPath();

    std::string exportPath;
    std::string selectedProjectPath;
    bool successfulExport;
};


#endif //TS_TIMETRACKER_TS_COMMANDEXPORT_H
