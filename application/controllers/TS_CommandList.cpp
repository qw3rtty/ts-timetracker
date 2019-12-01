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
#include "../../helpers/headers/TS_Helper.h"
#include "./headers/TS_Command.h"
#include "./headers/TS_CommandList.h"

/**
 * @inherit
 */
TS_CommandList::TS_CommandList()
{
    this->isTestMode = false;
    this->projectKey = -1;
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

    TS_Helper helper;
    std::map<int, std::string>::iterator listIterator = this->list.begin();
    while (listIterator != this->list.end())
    {
        std::cout << listIterator->first << " => " << listIterator->second;

        if (listIterator->first == this->projectKey)
        {
            std::cout << helper.color << " [selected]" << helper.noColor;
        }

        std::cout << std::endl;
        listIterator++;
    }

    return true;
}

/**
 * @inherit
 */
bool TS_CommandList::prepare()
{
    return true;
}

/**
 * Set given project list
 * @param std::map<int, std::string> list
 */
void TS_CommandList::setProjectList(std::map<int, std::string> list)
{
    this->list = list;
}

/**
 * Set given project key
 * @param int key
 */
void TS_CommandList::setProjectKey(int key)
{
    this->projectKey = key;
}

/**
 * Set test mode
 * @param testMode
 */
void TS_CommandList::setTestMode(bool testMode)
{
    this->isTestMode = testMode;
}