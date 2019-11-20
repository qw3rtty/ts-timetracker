#include <stdio.h>
#include <iostream>
#include <cstring>

#include "./helpers/headers/TS_Helper.h"
#include "./helpers/headers/TS_Info.h"

#include "./application/controllers/headers/TS_Base.h"
#include "./application/controllers/headers/TS_CommandDelegator.h"
#include "./application/controllers/headers/TS_Command.h"
#include "./application/controllers/headers/TS_CommandHelp.h"

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char **argv)
{
    TS_Helper helper;
    TS_Info info;
    info.welcome();
    info.showInfo();

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt */
        std::cout << helper.color << "ts-timetracker> " << helper.noColor;

        /* Read a line of user input of maximum size 2048 */
        std::cin >> input;

        commandDelegator->setCommandWithAttributes(input);
        if (commandDelegator->isCommandValid())
        {
            commandDelegator->runCommand();
        }
        else
        {
            std::cout << "You entered a wrong command! \n";
            std::cout << "Type 'help' to get more informations. \n";
        }
    }

    return 0;
}
