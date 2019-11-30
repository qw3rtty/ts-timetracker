# BASIC
CC = g++
NAME = ts-timetracker
MAIN = main.cpp

# CONFIG
CONFIG = ./config/TS_ConfigReader.cpp ./config/TS_ConfigReader.h

# PATHS
HELPERSPATH = ./helpers
HELPERSHEADERPATH = $(HELPERSPATH)/headers

CONTROLLERSPATH = ./application/controllers
CONTROLLERSHEADERPATH = $(CONTROLLERSPATH)/headers

MODELSPATH = ./application/models
MODELSHEADERPATH = $(MODELSPATH)/headers

# FILES
HELPERHEADERS = \
    $(HELPERSHEADERPATH)/TS_Helper.h \
    $(HELPERSHEADERPATH)/TS_Info.h

HELPERS = \
    $(HELPERSPATH)/TS_Helper.cpp \
    $(HELPERSPATH)/TS_Info.cpp

CONTROLLERHEADERS = \
    $(CONTROLLERSHEADERPATH)/TS_Base.h \
    $(CONTROLLERSHEADERPATH)/TS_Application.h \
    $(CONTROLLERSHEADERPATH)/TS_Command.h \
    $(CONTROLLERSHEADERPATH)/TS_CommandHelp.h \
    $(CONTROLLERSHEADERPATH)/TS_CommandList.h \
    $(CONTROLLERSHEADERPATH)/TS_CommandShowConfig.h \
    $(CONTROLLERSHEADERPATH)/TS_CommandTimestamp.h

CONTROLLERS = \
    $(CONTROLLERSPATH)/TS_Base.cpp \
    $(CONTROLLERSPATH)/TS_Application.cpp \
    $(CONTROLLERSPATH)/TS_Command.cpp \
    $(CONTROLLERSPATH)/TS_CommandHelp.cpp \
    $(CONTROLLERSPATH)/TS_CommandList.cpp \
    $(CONTROLLERSPATH)/TS_CommandShowConfig.cpp \
    $(CONTROLLERSPATH)/TS_CommandTimestamp.cpp

MODELHEADERS = \
    $(MODELSHEADERPATH)/TS_Model.h \
    $(MODELSHEADERPATH)/TS_ModelFilesystem.h

MODELS = \
    $(MODELSPATH)/TS_Model.cpp \
    $(MODELSPATH)/TS_ModelFilesystem.cpp

# TESTS
TESTFILENAME = ts-test
TESTFILES = ./tests/TS_UnitTest.cpp

build:
	@echo Compiling ts-timetracker ...
	@$(CC) -o $(NAME) $(CONFIG) $(MAIN) $(HELPERS) $(HELPERHEADERS) $(MODELS) $(MODELHEADERS) $(CONTROLLERS) $(CONTROLLERHEADERS)
	@echo Successfully compiled

test:
	@echo Compiling unit test ...
	@$(CC) -o $(TESTFILENAME) $(CONFIG) $(TESTFILES) $(HELPERS) $(HELPERHEADERS) $(MODELS) $(MODELHEADERS) $(CONTROLLERS) $(CONTROLLERHEADERS)
	@echo Successfully compiled
	@echo Run unit test:
	@./ts-test
