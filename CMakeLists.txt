cmake_minimum_required(VERSION 3.13)
project(ts-timetracker)

set(CMAKE_CXX_STANDARD 14)

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

# Testing section
enable_testing()

add_executable(ts-test tests/TS_UnitTest.cpp
    application/controllers/TS_Application.cpp
    application/controllers/TS_Base.cpp
    application/controllers/TS_Command.cpp
    application/controllers/TS_CommandExport.cpp
    application/controllers/TS_CommandHelp.cpp
    application/controllers/TS_CommandList.cpp
    application/controllers/TS_CommandRemove.cpp
    application/controllers/TS_CommandSave.cpp
    application/controllers/TS_CommandTimestamp.cpp
    application/controllers/TS_CommandTimestampStart.cpp
    application/controllers/TS_CommandTimestampStop.cpp
    application/controllers/TS_CommandTouch.cpp
    application/controllers/TS_CommandUse.cpp
    application/models/TS_Model.cpp
    application/models/TS_ModelFilesystem.cpp
    application/views/TS_View.cpp
    application/views/TS_ViewTerminal.cpp
    config/TS_ConfigReader.cpp
    helpers/TS_Helper.cpp
    helpers/TS_Info.cpp
    libaries/VariadicTable.h
    factories/TS_FactoryView.cpp
    factories/TS_FactoryCommand.cpp
)
add_test(TS-UnitTest ts-test)
