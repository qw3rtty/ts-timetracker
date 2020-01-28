/**
 * TS-FactoryView
 *
 * Factory class for view building.
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef TS_TIMETRACKER_TS_FACTORYVIEW_H
#define TS_TIMETRACKER_TS_FACTORYVIEW_H

#include "TS_IView.h"

class TS_FactoryView
{
public:
    TS_FactoryView();
    ~TS_FactoryView() = default;
    static TS_IView* build();
};

#endif //TS_TIMETRACKER_TS_FACTORYVIEW_H
