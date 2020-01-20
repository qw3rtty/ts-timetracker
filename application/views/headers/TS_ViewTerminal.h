/**
 * TS-ViewTerminal
 *
 * Terminal, text driven view class.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_VIEWTERMINAL_H
#define TS_TIMETRACKER_TS_VIEWTERMINAL_H

#include "TS_View.h"

class TS_ViewTerminal : public TS_View
{
public:
    TS_ViewTerminal();
    ~TS_ViewTerminal() = default;
    void render() override;
};


#endif //TS_TIMETRACKER_TS_VIEWTERMINAL_H
