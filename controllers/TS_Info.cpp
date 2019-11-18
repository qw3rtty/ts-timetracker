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

#include <stdio.h>
#include <iostream>
#include "./headers/TS_Info.h"

// TODO: Create color library!
static char color[] = "\033[0;33m";
static char noColor[] = "\033[0m";

/**
 * Constructor
 */
TS_Info::TS_Info()
{}

/**
 * Show's welcome message
 */
void TS_Info::welcome()
{
    std::cout << color << "████████╗███████╗   ████████╗██╗███╗   ███╗███████╗████████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗ \n" << noColor;
    std::cout << color << "╚══██╔══╝██╔════╝   ╚══██╔══╝██║████╗ ████║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗ \n" << noColor;
    std::cout << color << "   ██║   ███████╗█████╗██║   ██║██╔████╔██║█████╗     ██║   ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝ \n" << noColor;
    std::cout << color << "   ██║   ╚════██║╚════╝██║   ██║██║╚██╔╝██║██╔══╝     ██║   ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗ \n" << noColor;
    std::cout << color << "   ██║   ███████║      ██║   ██║██║ ╚═╝ ██║███████╗   ██║   ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║ \n" << noColor;
    std::cout << color << "   ╚═╝   ╚══════╝      ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ \n" << noColor;
}

/**
 * Show's basic informations
 */
void TS_Info::showInfo()
{
    std::cout << "Version pre-alpha-0.1.0 \n";
    std::cout << "Press Ctrl+c to Exit \n";
    std::cout << "No commands implemented yet :( \n";
}