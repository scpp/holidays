#***************************************************************************
#*   Copyright (C) 2020 by Vladimir Mirnyy, mirnyy.eu                      *
#*                                                                         *
#*   This program is free software; you can redistribute it and/or modify  *
#*   it under the terms of the MIT License                                 *
#***************************************************************************

cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_STANDARD 14)

project(holidays)

include(CheckCXXCompilerFlag)
include(ExternalProject)

CHECK_CXX_COMPILER_FLAG(-std=c++2a COMPILER_SUPPORTS_CXX2A)

if(COMPILER_SUPPORTS_CXX2A)
    set(CMAKE_CXX_STANDARD 20)
else()
    set(CMAKE_CXX_STANDARD 14)
endif()

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(date
    GIT_REPOSITORY https://github.com/HowardHinnant/date.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include/date)

file(GLOB _sources *.cpp)
file(GLOB _headers *.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})
add_dependencies(${PROJECT_NAME} date)
