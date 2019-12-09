# ts-timetracker
Simple interactive command line timetracker.  
![TS-Timetracker Screenshot](timetracker.png)  

## Installation
Clone the repo:  
`git clone https://github.com/thomasschwarz96/ts-timetracker.git`  

Navigate to the folder:  
`cd ts-timetracker/`

To make the unit tests, follow the steps below:  
`make test`  

For building the binaries, follow the steps below:  
`make build`  

Installing it completely is in work!

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
- [ ] Create export of projects
- [ ] Add more models