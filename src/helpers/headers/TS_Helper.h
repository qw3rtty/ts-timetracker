/**
 * TS-Helper
 *
 * Helper class for application.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_HELPER_H
#define TS_TIMETRACKER_TS_HELPER_H

#include <cstdio>
#include <ctime>
#include <string>

class TS_Helper
{
public:
    TS_Helper();
    ~TS_Helper() = default;
    const char *color;
    const char *noColor;
    const char *tab;
    const char *doubleTab;

    static std::string formatTimestamp(std::time_t timestamp);
};

#endif //TS_TIMETRACKER_TS_HELPER_H
