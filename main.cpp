#include <stdio.h>
#include <iostream>
#include "./application/controllers/headers/TS_Base.h"
#include "./application/controllers/headers/TS_Info.h"
#include "./application/controllers/headers/TS_CommandDelegator.h"

/* Declare a buffer for user input of size 2048 */
static char input[2048];

// TODO: Create color library!
static char color[] = "\033[0;33m";
static char noColor[] = "\033[0m";

int main(int argc, char **argv)
{
    TS_Info info;
    info.welcome();
    info.showInfo();

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt */
        std::cout << color << "ts-timetracker> " << noColor;

        /* Read a line of user input of maximum size 2048 */
        std::cin >> input;

        commandDelegator->setCommand(input);
        if (commandDelegator->isCommandValid())
        {
            std::cout << "Commands coming... \n";
            std::cout << "I am working :) \n";
        }
        else
        {
            std::cout << "You entered a wrong command! \n";
            std::cout << "Type 'help' to get more informations. \n";
        }
    }

    return 0;
}
