# ts-timetracker
Simple interactive command line timetracker.  
![TS-Timetracker Screenshot](timetracker.png)  

## Installation
Follow the steps below for installating:  
`$ git clone https://github.com/thomasschwarz96/ts-timetracker.git`  
`$ cd ts-timetracker`  
`$ ./build.sh`  
During the installing process you have to enter the location of your config file.  
Possible configuration values see below.

**Installation for windows is coming soon.**

## Configuration
Name of the config file: **.ts-timetracker.conf**  
Possible config values:  
- `timeFormat=%d.%m.%Y %T` format is used for displaying time
- `projectsPath=/home/.ts-timetracker/` path is used for creating, saving and deleting projects
- `storage=filesystem` indicates which model should used
- `view=terminal` indicates which view should used

##### Available Models:
- filesystem: save's the data into files, location is configured by "projectsPath"

##### Available Views:
- terminal: run's in the terminal, with and simple interactive command line interface

## Libaries in usage
- For printing the table: https://github.com/friedmud/variadic_table

## ToDo
- [x] Create export of projects
- [ ] Implement GUI view

## Other
If you got some problems, improvements or changes let me know.  
I appreciate every single help!
