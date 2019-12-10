cmake_minimum_required(VERSION 3.13)
project(ts-timetracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(ts-timetracker main.cpp)

add_subdirectory(application/controllers)
add_subdirectory(application/models)
add_subdirectory(config)
add_subdirectory(helpers)

include_directories(application/controllers/headers)
include_directories(application/controllers)
include_directories(application/models/headers)
include_directories(application/models)
include_directories(application/views/headers)
include_directories(application/views)
include_directories(config)
include_directories(helpers/headers)
include_directories(helpers)

