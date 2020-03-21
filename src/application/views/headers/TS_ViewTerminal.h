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

#include "TS_IView.h"
#include "TS_IModel.h"

class TS_ViewTerminal : public TS_IView
{
public:
    TS_ViewTerminal();
    ~TS_ViewTerminal() override = default;

    void setModel(TS_IModel *newModel) override;
    void render() override;
};


#endif //TS_TIMETRACKER_TS_VIEWTERMINAL_H
