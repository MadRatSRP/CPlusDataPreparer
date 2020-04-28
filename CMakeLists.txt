# cmake_minimum_required(VERSION <specify CMake version here>)
project(CPlusDataPreparer)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPlusDataPreparer main.cpp Models.cpp NlCheats.cpp Constants.h)