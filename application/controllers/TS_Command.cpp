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

#include "./headers/TS_Command.h"

/**
 * Constructor
 * @param   char*   - Arguments entered by user
 */
TS_Command::TS_Command(char *arguments)
{
    this->arguments = arguments;
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