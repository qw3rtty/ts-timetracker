/**
 * TS-View
 *
 * Base view class.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_VIEW_H
#define TS_TIMETRACKER_TS_VIEW_H

#include "TS_Model.h"

class TS_View
{
public:
    TS_View();
    ~TS_View() = default;
    void setModel(const TS_Model &newModel);
    virtual void render();

private:
    TS_Model model;
};


#endif //TS_TIMETRACKER_TS_VIEW_H
