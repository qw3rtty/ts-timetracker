cmake_minimum_required(VERSION 3.13)
project(ts-timetracker)
set(CMAKE_CXX_STANDARD 14)



# Prepare filesystem for installation
file(MAKE_DIRECTORY $ENV{HOME}/.config/ts-timetracker/)
file(MAKE_DIRECTORY $ENV{HOME}/.config/ts-timetracker/projects/)
configure_file(./.ts-timetracker.conf $ENV{HOME}/.config/ts-timetracker/ts-timetracker.conf)



# Compile definitions
add_executable(ts-timetracker main.cpp libaries/VariadicTable.h)

set(TSConfigPath "$ENV{HOME}/.config/ts-timetracker/ts-timetracker.conf")
add_compile_definitions(TS_CONFIG_PATH="${TSConfigPath}")

add_subdirectory(application/controllers)
add_subdirectory(application/models)
add_subdirectory(application/views)
add_subdirectory(config)
add_subdirectory(factories)
add_subdirectory(helpers)

include_directories(application/controllers/headers)
include_directories(application/controllers)
include_directories(application/models/headers)
include_directories(application/models)
include_directories(application/views/headers)
include_directories(application/views)
include_directories(config)
include_directories(factories/headers)
include_directories(factories)
include_directories(helpers/headers)
include_directories(helpers)



# Testing definitions
enable_testing()

# Config reader test
add_executable(ts-unittest-config tests/TS_UnitTest_Config.cpp
    config/TS_ConfigReader.cpp
)
add_test(Test-Config ts-unittest-config)

# Export command test
add_executable(ts-unittest-cmd-export tests/TS_UnitTest_CmdExport.cpp
    application/controllers/TS_Base.cpp
    application/controllers/TS_Application.cpp
    application/controllers/TS_Command.cpp
    application/controllers/TS_CommandExport.cpp
    application/models/TS_ModelFilesystem.cpp
    config/TS_ConfigReader.cpp
    helpers/TS_Helper.cpp
)
add_test(Test-CmdExport ts-unittest-cmd-export)

# Help command test
add_executable(ts-unittest-cmd-help tests/TS_UnitTest_CmdHelp.cpp
    application/controllers/TS_Command.cpp
    application/controllers/TS_CommandHelp.cpp
)
add_test(Test-CmdHelp ts-unittest-cmd-help)



# Install definitons
install(TARGETS ts-timetracker DESTINATION /usr/local/bin/)

# Uninstall definitins
add_custom_target(uninstall
    "${CMAKE_COMMAND}" -P "cmake_uninstall.cmake"
)