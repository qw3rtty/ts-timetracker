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
              << " _________      _____ _                _                  _" << std::endl;
    std::cout << "|_   _/ ___|    |_   _(_)_ __ ___   ___| |_ _ __ __ _  ___| | _____ _ __" << std::endl;
    std::cout << "  | | \\___ \\ _____| | | | '_ ` _ \\ / _ \\ __| '__/ _` |/ __| |/ / _ \\ '__|" << std::endl;
    std::cout << "  | |  ___) |_____| | | | | | | | |  __/ |_| | | (_| | (__|   <  __/ |" << std::endl;
    std::cout << "  |_| |____/      |_| |_|_| |_| |_|\\___|\\__|_|  \\__,_|\\___|_|\\_\\___|_|" << std::endl << helper.noColor;

}

/**
 * Show's basic informations
 */
void TS_Info::showInfo()
{
    std::cout << "Version 0.1.0" << std::endl;
    std::cout << "Press 'Ctrl+c', type 'exit' or 'q' to quit." << std::endl;
}