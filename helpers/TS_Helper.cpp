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

#include "./headers/TS_Helper.h"

/**
 * Constructor
 */
TS_Helper::TS_Helper()
{
    this->color = "\033[0;33m";
    this->noColor = "\033[0m";
    this->tab = "\t";
    this->doubleTab = "\t\t";
}
