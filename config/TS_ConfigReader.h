/**
 * TS-ConfigReader
 *
 * Config reader class.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_CONFIGREADER_H
#define TS_TIMETRACKER_TS_CONFIGREADER_H

#include <iostream>
#include <string>
#include <map>

class TS_ConfigReader
{
public:
    TS_ConfigReader();
    bool configLoaded;
    void showConfig();
    std::string getConfigEntry(std::string entry);

private:
    std::string filename;
    std::map<std::string, std::string> entries;
    bool loadConfig();
};


#endif //TS_TIMETRACKER_TS_CONFIGREADER_H
