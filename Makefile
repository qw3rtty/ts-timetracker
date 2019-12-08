# BASIC
CC = g++
NAME = ts-timetracker
MAIN = main.cpp

# CONFIG
CONFIG = ./config/TS_ConfigReader.cpp

# PATHS
HELPERSPATH = ./helpers
CONTROLLERSPATH = ./application/controllers
MODELSPATH = ./application/models

# FILES
HELPERS = \
    $(HELPERSPATH)/TS_Helper.cpp \
    $(HELPERSPATH)/TS_Info.cpp

CONTROLLERS = \
    $(CONTROLLERSPATH)/TS_Base.cpp \
    $(CONTROLLERSPATH)/TS_Application.cpp \
    $(CONTROLLERSPATH)/TS_Command.cpp \
    $(CONTROLLERSPATH)/TS_CommandHelp.cpp \
    $(CONTROLLERSPATH)/TS_CommandList.cpp \
    $(CONTROLLERSPATH)/TS_CommandTimestamp.cpp \
    $(CONTROLLERSPATH)/TS_CommandTouch.cpp

MODELS = \
    $(MODELSPATH)/TS_Model.cpp \
    $(MODELSPATH)/TS_ModelFilesystem.cpp

# TESTS
TESTFILENAME = ts-test
TESTFILES = ./tests/TS_UnitTest.cpp

build:
	@echo Compiling ts-timetracker ...
	@$(CC) -o $(NAME) $(CONFIG) $(MAIN) $(HELPERS) $(MODELS) $(CONTROLLERS)
	@echo Successfully compiled

test:
	@echo Compiling unit test ...
	@$(CC) -o $(TESTFILENAME) $(CONFIG) $(TESTFILES) $(HELPERS) $(MODELS) $(CONTROLLERS)
	@echo Successfully compiled
	@echo Run unit test:
	@./ts-test
