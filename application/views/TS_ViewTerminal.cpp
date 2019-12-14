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

#include "TS_View.h"
#include "TS_ViewTerminal.h"

#include <iostream>

/**
 * @inherit
 */
TS_ViewTerminal::TS_ViewTerminal() : TS_View()
{}

/**
 * @inherit
 */
void TS_ViewTerminal::render()
{
    std::cout << "VIEW TERMINAL" << std::endl;
}