/**
 * TS-IView
 *
 * Interface for all views.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_IVIEW_H
#define TS_TIMETRACKER_TS_IVIEW_H

#include "TS_IModel.h"

class TS_IView
{
public:
    virtual ~TS_IView() = default;
    virtual void setModel(TS_IModel *newModel)  = 0;
    virtual void render() = 0;

protected:
    TS_IModel *model = nullptr;
};


#endif //TS_TIMETRACKER_TS_IVIEW_H
