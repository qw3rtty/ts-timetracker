#!/bin/bash
# ====================================================================
# _____ _                      ___     _                       ___  __
#|_   _| |_  ___ _ __  __ _ __/ __| __| |___ __ ____ _ _ _ ___/ _ \/ /
# | | | ' \/ _ \ '  \/ _` (_-<__ \/ _| ' \ V  V / _` | '_|_ /\_, / _ \
# |_| |_||_\___/_|_|_\__,_/__/___/\__|_||_\_/\_/\__,_|_| /__| /_/\___/
# ====================================================================

COLOR="\033[0;33m"
NOCOLOR="\033[0m"

printf "${COLOR}=================================${NOCOLOR}\n"
printf "${COLOR}TS-Timetracker preparing build.${NOCOLOR}\n"

printf "Enter path to the config file:\n"
read configFilePath

printf "${COLOR}Start building...${NOCOLOR}\n\n"
cmake -DTSConfigPath="$configFilePath" ./CMakeLists.txt

printf "${COLOR}TS-Timetracker build preparing finished.${NOCOLOR}\n\n"
printf "${COLOR}=================================${NOCOLOR}\n"

make