# TS-Timetracker
**Simple interactive command line timetracker.**  
![TS-Timetracker Screenshot](ts-timetracker.gif)  
This tool allows you to track your time for all your projects or needs. You can manage your projects and export it for your needs.  

## :page_facing_up: Table of Contents
- [Installation](#pager-installation)
- [Uninstall](#pager-uninstall)
- [Unit tests](#heavy_check_mark-unit-tests)
- [Usage](#clipboard-usage)
- [Configuration](#wrench-configuration)
  - [Available Models](#available-models)
  - [Available Views](#available-views)
- [Contributing](#memo-contributing)
- [Roadmap](#car-roadmap)
- [Known bugs](#bug-known-bugs)
- [Libaries in usage](#books-libaries-in-usage)
- [Supported by](#supported-by)
- [License](#scroll-license)

## :pager: Installation
Follow the steps below for installing:  
```bash
$ git clone https://github.com/thomasschwarz96/ts-timetracker.git  
$ cd ts-timetracker  
$ cmake .  
$ make  
$ sudo make install
```

## :pager: Uninstall
Follow the steps below for uninstalling:  
```bash
$ cd ts-timetracker # should be the same directory where the repository was cloned into  
$ sudo make uninstall
```

If there is an error during the uninstall process or you don't have the directory anymore following the steps below:  
```bash
$ sudo updatedb  
$ locate ts-timetracker # $ locate ts-timetracker | grep /usr - if the output is to large  
$ sudo rm {PATH}/ts-timetracker # where {PATH} is the full path to the binary  
```

## :heavy_check_mark: Unit tests
Follow the steps below for unit testing after the installation guide:  
```bash
$ make test    
```

## :clipboard: Usage
```bash
$ ts-timetracker
```
That's it. Now the interactive command line starts and you can start to track your times on your projects or for your needs.  
To Exit, just type '**exit**' or press <kbd>Ctrl</kbd> + <kbd>c</kbd>.  
Here are all commands you can use:

| COMMAND              | DESCRIPTION                                                               |
| -------------------- | ------------------------------------------------------------------------- |
| help                 | Show's the help menu                                                      |
| touch &lt;name&gt;   | Create's a new project with entered name                                  |
| rm &lt;name&gt;      | Delete's entered project                                                  |
| ls &lt;item&gt;      | List selected items (use 'projects', 'config' or 'times')                 |
| use &lt;name&gt;     | Set project to track time on, a name from 'list' command                  |
| start                | Start's timetracking                                                      |
| stop                 | Stop's timetracking                                                       |
| save &lt;comment&gt; | Save new timetrack on selected project with entered comment               |
| export &lt;p&gt;     | Export selected project to given path (selected project by 'use' command) |

## :wrench: Configuration
Default path of the config file: **~/.config/ts-timetracker/**  
Name of the config file: **ts-timetracker.conf**  
The config file will be generated automatically while installation.  

Possible config values:  

| OPTION       | DEFAULT VALUES                   | DESCRIPTION                                             |
| ------------ | -------------------------------- | ------------------------------------------------------- |
| timeFormat   | %d.%m.%Y %T                      | format is used for displaying time                      |  
| projectsPath | .config/ts-timetracker/projects/ | path is used for creating, saving and deleting projects |  
| storage      | filesystem                       | indicates which model should used                       |  
| view         | terminal                         | indicates which view should used                        |  

Feel free to change your config values to your needs!  

##### Available Models:
The key **storage** indicates which model should be used.  
Following list shows all available models:  
- filesystem: save's the data into files, location is configured by "projectsPath"

##### Available Views:
The key **view** indicates which view should be used.  
Following list shows all available views:  
- terminal: run's in the terminal, with and simple interactive command line interface

## :memo: Contributing
If you want to contribute check the [CONTRIBUTING.md](https://github.com/thomasschwarz96/ts-timetracker/blob/master/.github/CONTRIBUTING.md)

## :car: Roadmap
- [x] Create interface for models
- [x] Create interface for views
- [x] Improve performance of filesystem model
- [x] Improve unit tests
- [ ] Improve make file
- [ ] Add more models for different databases(?)  
  - [ ] SQLite(?)  
  - [ ] MySQL(?)  
- [ ] Add more formats for exporting projects
  - [ ] Plaintext
  - [ ] XML
- [ ] Remove dependency of library

## :bug: Known bugs
Currently are no bugs known/reported.  
If you find any bugs, don't hesitate and open an issue :)

## :books: Libaries in usage
- For printing the table: https://github.com/friedmud/variadic_table

## :heart_eyes: Supported by
I can proudly say, that I get support from:  

[![Supported by JetBrains](jetbrains.svg)](https://www.jetbrains.com/?from=ts-timetracker)

## :scroll: License
[MIT-License](https://choosealicense.com/licenses/mit/) © [Thomas Schwarz](https://github.com/thomasschwarz96)
