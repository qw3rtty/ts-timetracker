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

#include "TS_IView.h"
#include "TS_ViewTerminal.h"

#include <iostream>
#include <cstring>

#include "TS_ConfigReader.h"
#include "TS_Helper.h"
#include "TS_Info.h"
#include "TS_ModelFilesystem.h"
#include "TS_Command.h"
#include "TS_FactoryCommand.h"
#include "TS_Application.h"

/**
 * @inherit
 */
TS_ViewTerminal::TS_ViewTerminal() : TS_IView()
{
    this->model = new TS_ModelFilesystem();
}

/**
 * @inherit
 */
void TS_ViewTerminal::render()
{
    static char input[2048];
    TS_ConfigReader config;
    TS_Helper helper;

    TS_Info::welcome();
    if (!config.configLoaded)
    {
        std::cout << "No config file found!" << std::endl;
        std::cout << "Please check out the documentation: " << std::endl;
        std::cout << "https://raw.githubusercontent.com/thomasschwarz96/ts-timetracker/master/README.md" << std::endl;
        return;
    }
    TS_Info::showInfo();

    /* In a never ending loop */
    while (true)
    {
        /* Output our prompt */
        std::cout << helper.color << "ts-timetracker> " << helper.noColor;

        /* Read a line of user input of maximum size 2048 */
        std::cin.getline(input, sizeof(input));

        // Check if user want to exit
        if (strcmp(input, "exit") == 0)
        {
            std::cout << "Goodbye!" << std::endl;
            return;
        }

        application->setCommandWithAttributes(input);
        if (application->isCommandValid())
        {
            TS_ModelFilesystem* model = new TS_ModelFilesystem();
            model->setProject(application->getSelectedProject());

            TS_Command *command = TS_FactoryCommand::build(
                application->getCommand(),
                application->getArguments(),
                model
            );

            if (command != nullptr)
            {
                command->execute();
                std::cout << command->getMessage().str() << std::endl;
            }
        }
        else
        {
            std::cout << "You entered a wrong command! \n";
            std::cout << "Type 'help' to get more informations. \n";
        }
    }
}

/**
 * Setter for model
 * @param   TS_IModel*   newModel
 */
void TS_ViewTerminal::setModel(TS_IModel *newModel)
{
    this->model = newModel;
}
