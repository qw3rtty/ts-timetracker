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
#include "./headers/TS_Info.h"

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
    puts("████████╗███████╗   ████████╗██╗███╗   ███╗███████╗████████╗██████╗  █████╗  ██████╗██╗  ██╗███████╗██████╗");
    puts("╚══██╔══╝██╔════╝   ╚══██╔══╝██║████╗ ████║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔══██╗");
    puts("   ██║   ███████╗█████╗██║   ██║██╔████╔██║█████╗     ██║   ██████╔╝███████║██║     █████╔╝ █████╗  ██████╔╝");
    puts("   ██║   ╚════██║╚════╝██║   ██║██║╚██╔╝██║██╔══╝     ██║   ██╔══██╗██╔══██║██║     ██╔═██╗ ██╔══╝  ██╔══██╗");
    puts("   ██║   ███████║      ██║   ██║██║ ╚═╝ ██║███████╗   ██║   ██║  ██║██║  ██║╚██████╗██║  ██╗███████╗██║  ██║");
    puts("   ╚═╝   ╚══════╝      ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝");
}

/**
 * Show's basic informations
 */
void TS_Info::showInfo()
{
    puts("Version pre-alpha-0.1.0");
    puts("Press Ctrl+c to Exit\n");
}