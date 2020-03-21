cmake_minimum_required(VERSION 3.13)
project(ts-timetracker)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)



# Prepare filesystem for installation
file(MAKE_DIRECTORY $ENV{HOME}/.config/ts-timetracker/)
file(MAKE_DIRECTORY $ENV{HOME}/.config/ts-timetracker/projects/)
configure_file(./config/ts-timetracker.conf $ENV{HOME}/.config/ts-timetracker/ts-timetracker.conf)



# Compile definitions
add_executable(ts-timetracker src/main.cpp src/libaries/VariadicTable.h)

set(TSConfigPath "$ENV{HOME}/.config/ts-timetracker/ts-timetracker.conf")
add_compile_definitions(TS_CONFIG_PATH="${TSConfigPath}")

add_subdirectory(src/application/controllers)
add_subdirectory(src/application/models)
add_subdirectory(src/application/views)
add_subdirectory(src/config)
add_subdirectory(src/factories)
add_subdirectory(src/helpers)

include_directories(src/application/controllers/headers)
include_directories(src/application/controllers)
include_directories(src/application/models/headers)
include_directories(src/application/models)
include_directories(src/application/views/headers)
include_directories(src/application/views)
include_directories(src/config)
include_directories(src/factories/headers)
include_directories(src/factories)
include_directories(src/helpers/headers)
include_directories(src/helpers)



# Testing definitions
enable_testing()

# Config reader test
add_executable(ts-unittest-config tests/TS_UnitTest_Config.cpp
    src/config/TS_ConfigReader.cpp
)
add_test(Test-Config ts-unittest-config)

# Help command test
add_executable(ts-unittest-cmd-help tests/TS_UnitTest_CmdHelp.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandHelp.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
)
add_test(Test-CmdHelp ts-unittest-cmd-help)

# Touch command test
add_executable(ts-unittest-cmd-touch tests/TS_UnitTest_CmdTouch.cpp
    src/application/controllers/TS_Base.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandTouch.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-CmdTouch ts-unittest-cmd-touch)

# Model filesystem test
add_executable(ts-unittest-model-filesystem tests/TS_UnitTest_ModelFilesystem.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-ModelFilesystem ts-unittest-model-filesystem)

# Use command test
add_executable(ts-unittest-cmd-use tests/TS_UnitTest_CmdUse.cpp
    src/application/controllers/TS_Base.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandUse.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-CmdUse ts-unittest-cmd-use)

# Export command test
add_executable(ts-unittest-cmd-export tests/TS_UnitTest_CmdExport.cpp
    src/application/controllers/TS_Base.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandExport.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-CmdExport ts-unittest-cmd-export)

# Remove command test
add_executable(ts-unittest-cmd-remove tests/TS_UnitTest_CmdRemove.cpp
    src/application/controllers/TS_Base.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandRemove.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-CmdRemove ts-unittest-cmd-remove)

# Timestamp command test
add_executable(ts-unittest-cmd-timestamp tests/TS_UnitTest_CmdTimestamp.cpp
    src/application/controllers/TS_Base.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandTimestamp.cpp
    src/application/controllers/TS_CommandTimestampStart.cpp
    src/application/controllers/TS_CommandTimestampStop.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-CmdTimestamp ts-unittest-cmd-timestamp)

# Save command test
add_executable(ts-unittest-cmd-save tests/TS_UnitTest_CmdSave.cpp
    src/application/controllers/TS_Base.cpp
    src/application/controllers/TS_Application.cpp
    src/application/controllers/TS_Command.cpp
    src/application/controllers/TS_CommandSave.cpp
    src/application/models/TS_ModelFilesystem.cpp
    src/config/TS_ConfigReader.cpp
    src/helpers/TS_Helper.cpp
)
add_test(Test-CmdSave ts-unittest-cmd-save)


# Install definitons
install(TARGETS ts-timetracker DESTINATION /usr/local/bin/)

# Uninstall definitins
add_custom_target(uninstall
    "${CMAKE_COMMAND}" -P "cmake_uninstall.cmake"
)