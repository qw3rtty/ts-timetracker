#include <iostream>

#include "TS_ConfigReader.h"
#include "TS_Helper.h"
#include "TS_Info.h"
#include "TS_Application.h"
#include "TS_ViewTerminal.h"

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char **argv)
{
    TS_ViewTerminal view; // TODO: use view!
    TS_ConfigReader config;
    TS_Helper helper;

    TS_Info::welcome();
    if (!config.configLoaded)
    {
        std::cout << "No config file found!" << std::endl;
        std::cout << "Please check out the documentation: " << std::endl;
        std::cout << "https://raw.githubusercontent.com/thomasschwarz96/ts-timetracker/master/README.md" << std::endl;
        return 0;
    }
    TS_Info::showInfo();

    /* In a never ending loop */
    while (true)
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
