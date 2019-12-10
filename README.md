# ts-timetracker
Simple interactive command line timetracker.  
![TS-Timetracker Screenshot](timetracker.png)  

## Installation
Installation guide coming soon.

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
