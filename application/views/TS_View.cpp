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

#include <TS_ModelFilesystem.h>
#include "TS_View.h"

/**
 * Constructor
 */
TS_View::TS_View()
{
    this->model = TS_ModelFilesystem();
}

/**
 * Set model of view
 * @param model
 */
void TS_View::setModel(const TS_ModelFilesystem &newModel)
{
    this->model = newModel;
}

/**
 * Rendering data
 */
void TS_View::render()
{}