# ts-timetracker
Simple interactive command line timetracker.  
![TS-Timetracker Screenshot](timetracker.png)  

## Installation
Follow the steps below for installating:  
`$ git clone https://github.com/thomasschwarz96/ts-timetracker.git`  
`$ cd ts-timetracker`  
`$ ./build.sh`  

## Configuration
Name of the config file: **.ts-timetracker.conf**  
Possible config values:  
- `timeFormat=%d.%m.%Y %T` format is used for displaying time
- `projectsPath=/home/.ts-timetracker/` path is used for creating, saving and deleting projects
- `storage=filesystem` indicates which model should used

-- --

Available Models:
- Filesystem: save's the data into files, location is configured by "projectsPath"

## ToDo
- [ ] Improve unit tests
- [ ] Create export of projects
- [ ] Add more models
