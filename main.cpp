#include <stdio.h>
#include <iostream>
#include <cstring>

#include "./config/TS_ConfigReader.h"
#include "./helpers/headers/TS_Helper.h"
#include "./helpers/headers/TS_Info.h"

#include "./application/controllers/headers/TS_Base.h"
#include "application/controllers/headers/TS_Application.h"

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char **argv)
{
    TS_ConfigReader config;
    TS_Helper helper;
    TS_Info info;

    info.welcome();
    if (!config.configLoaded)
    {
        std::cout << "No config file found!" << std::endl;
        std::cout << "Please check out the documentation: " << std::endl;
        std::cout << "https://raw.githubusercontent.com/thomasschwarz96/ts-timetracker/master/README.md" << std::endl;
        return 0;
    }
    info.showInfo();

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt */
        std::cout << helper.color << "ts-timetracker> " << helper.noColor;

        /* Read a line of user input of maximum size 2048 */
        std::cin.getline(input, sizeof(input));

        application->setCommandWithAttributes(input);
        if (application->isCommandValid())
        {
            application->runCommand();
        }
        else
        {
            std::cout << "You entered a wrong command! \n";
            std::cout << "Type 'help' to get more informations. \n";
        }
    }

    return 0;
}
