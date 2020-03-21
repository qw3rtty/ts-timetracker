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

#include <string>

#include "TS_ConfigReader.h"
#include "TS_FactoryView.h"
#include "TS_IView.h"
#include "TS_ViewTerminal.h"

/**
 * Constructor
 */
TS_FactoryView::TS_FactoryView() = default;

/**
 * Factory for views
 * @return  TS_View  - View instance
 */
TS_IView* TS_FactoryView::build()
{
    TS_ConfigReader config;
    TS_IView *view;
    std::string configView = config.getConfigEntry("view");

    // Right now we have only one view :D
    view = new TS_ViewTerminal();

    return view;
}