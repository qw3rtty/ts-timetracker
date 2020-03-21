/**
 * TS-Command
 *
 * Abstract superclass for all commands
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include "TS_Command.h"
#include "TS_IModel.h"

/**
 * Constructor
 * @param   char*           - Arguments entered by user
 * @param   TS_IModel*      - Model which is configured
 */
TS_Command::TS_Command(char *arguments, TS_IModel* model)
{
    this->arguments = arguments;
    this->model = model;
    this->isTestMode = false;
}

/**
 * Execute command
 * @return  bool
 */
bool TS_Command::execute()
{
    return false;
}

/**
 * Prepares everything for correct execution
 * @return  bool
 */
bool TS_Command::prepare()
{
    return false;
}

/**
 * Set test mode
 * @param   testMode    - Determine test mode state
 */
void TS_Command::setTestMode(bool testMode)
{
    this->isTestMode = testMode;
}

/**
 * Get message of executed command
 * @return  std::ostringstream
 */
std::ostringstream TS_Command::getMessage()
{
    return std::ostringstream();
}
