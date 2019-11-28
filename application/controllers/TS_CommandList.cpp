/**
 * TS-CommandList
 *
 * List projects command
 *
 * @package     TS-TimeTracker
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2019, Thomas Schwarz
 * @license     MIT License (https://opensource.org/licenses/MIT)
 * @since       Version 0.1.0
 * @filesource
 */

#include <iostream>
#include <string>
#include <map>
#include <iterator>

#include "../../config/TS_ConfigReader.h"
#include "../models/headers/TS_ModelFilesystem.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandList.h"

/**
 * @inherit
 */
TS_CommandList::TS_CommandList()
{
    this->isTestMode = false;
}

/**
 * @inherit
 */
bool TS_CommandList::execute()
{
    this->prepare();

    if (this->isTestMode)
    {
        return true;
    }

    std::map<int, std::string>::iterator listIterator = this->list.begin();
    while (listIterator != this->list.end())
    {
        std::cout << listIterator->first << " => " << listIterator->second << std::endl;
        listIterator++;
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandList::prepare()
{
    this->list = this->model.getProjectList();
    return true;
}

/**
 * Set test mode
 * @param testMode
 */
void TS_CommandList::setTestMode(bool testMode)
{
    this->isTestMode = testMode;
}