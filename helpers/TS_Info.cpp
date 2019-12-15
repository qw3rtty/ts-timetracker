/**
 * TS-Info
 *
 * Displays informations
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include "TS_Helper.h"
#include "TS_Info.h"

/**
 * Constructor
 */
TS_Info::TS_Info() = default;

/**
 * Show's welcome message
 */
void TS_Info::welcome()
{
    TS_Helper helper;

    std::cout << helper.color
              << "████████╗███████╗   ████████╗██╗███╗   ███╗███████╗████████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗ " << std::endl;
    std::cout << "╚══██╔══╝██╔════╝   ╚══██╔══╝██║████╗ ████║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗ " << std::endl;
    std::cout << "   ██║   ███████╗█████╗██║   ██║██╔████╔██║█████╗     ██║   ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝ " << std::endl;
    std::cout << "   ██║   ╚════██║╚════╝██║   ██║██║╚██╔╝██║██╔══╝     ██║   ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗ " << std::endl;
    std::cout << "   ██║   ███████║      ██║   ██║██║ ╚═╝ ██║███████╗   ██║   ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║ " << std::endl;
    std::cout << "   ╚═╝   ╚══════╝      ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ " << std::endl << helper.noColor;
}

/**
 * Show's basic informations
 */
void TS_Info::showInfo()
{
    std::cout << "Version 0.1.0" << std::endl;
    std::cout << "Press 'Ctrl+c' or txpe 'exit' to Quit." << std::endl;
}