# ts-timetracker
Simple interactive command line timetracker.  
![TS-Timetracker Screenshot](timetracker.png)  

## Installation
Follow the steps below for installing:  
`$ git clone https://github.com/thomasschwarz96/ts-timetracker.git`  
`$ cd ts-timetracker`  
`$ cmake .`  
`$ make`  
`$ sudo make install`  

## Uninstall
Follow the steps below for uninstalling:  
`$ cd ts-timetracker`  should be the same directory where the repository was cloned into  
`$ sudo make uninstall`   

If there is an error during the uninstall process or you don't have the directory anymore following the steps below:  
`$ sudo updatedb`  
`$ locate ts-timetracker` or `$ locate ts-timetracker | grep /usr` if the output is to large  
`$ sudo rm {PATH}/ts-timetracker` where {PATH} is the full path to the binary

## Unit tests
Follow the steps below for unit testing after the installation guide:  
`$ make test`  
`$ ctest`  

## Configuration
Path of the config file: **~/.config/ts-timetracker/**  
Name of the config file: **ts-timetracker.conf**  
The config file will be generated automatically while installation.  

Possible config values:  
- `timeFormat=%d.%m.%Y %T` format is used for displaying time
- `projectsPath=.config/ts-timetracker/projects/` path is used for creating, saving and deleting projects
- `storage=filesystem` indicates which model should used
- `view=terminal` indicates which view should used

##### Available Models:
- filesystem: save's the data into files, location is configured by "projectsPath"

##### Available Views:
- terminal: run's in the terminal, with and simple interactive command line interface

## Contributing
Pull requests are welcome.  
For major changes, please open an issue first to discuss what you would like to change.  

Please make sure to update tests as appropriate.  
I appreciate every single help!

## ToDo
- [x] Create interface for models
- [x] Add tracked time amount to export
- [ ] Improve filesystem model
- [ ] Create multiple small unit tests

## Libaries in usage
- For printing the table: https://github.com/friedmud/variadic_table

## License
[MIT-License](https://choosealicense.com/licenses/mit/)
