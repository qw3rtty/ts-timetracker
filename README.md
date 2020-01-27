# ts-timetracker
Simple interactive command line timetracker.  
![TS-Timetracker Screenshot](ts-timetracker.gif)  

## :page_facing_up: Table of Contents
- [Installation](#pager-installation)
- [Uninstall](#pager-uninstall)
- [Unit tests](#heavy_check_mark-unit-tests)
- [Configuration](#wrench-configuration)
  - [Available Models](#available-models)
  - [Available Views](#available-views)
- [Contributing](#memo-contributing)
- [Roadmap](#car-roadmap)
- [Known bugs](#bug-known-bugs)
- [Libaries in usage](#books-libaries-in-usage)
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
$ ctest  
```

## :wrench: Configuration
Default path of the config file: **~/.config/ts-timetracker/**  
Name of the config file: **ts-timetracker.conf**  
The config file will be generated automatically while installation.  

Possible config values:  

| OPTION       | POSSIBLE VALUES / EXAMPLES       | DESCRIPTION                                             |
| ------------ | -------------------------------- | ------------------------------------------------------- |
| timeFormat   | %d.%m.%Y %T                      | format is used for displaying time                      |  
| projectsPath | .config/ts-timetracker/projects/ | path is used for creating, saving and deleting projects |  
| storage      | filesystem                       | indicates which model should used                       |  
| view         | terminal                         | indicates which view should used                        |  


##### Available Models:
- filesystem: save's the data into files, location is configured by "projectsPath"

##### Available Views:
- terminal: run's in the terminal, with and simple interactive command line interface

## :memo: Contributing
Pull requests are welcome.  
For major changes, please open an issue first to discuss what you would like to change.  

Please make sure to update tests as appropriate.  
I appreciate every single help!

## :car: Roadmap
- [x] Create interface for models
- [ ] Create interface for views
- [ ] Improve performance of filesystem model
- [ ] Improve unit tests
- [ ] Add more models for different databases 
  - [ ] SQLite
  - [ ] MySQL
- [ ] Add more formats for exporting projects
  - [ ] Plaintext
  - [ ] XML
- [ ] Remove dependency of library

## :bug: Known bugs
Currently are no bugs known/reported.

## :books: Libaries in usage
- For printing the table: https://github.com/friedmud/variadic_table

## :scroll: License
[MIT-License](https://choosealicense.com/licenses/mit/) © [Thomas Schwarz](https://github.com/thomasschwarz96)
