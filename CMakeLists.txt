cmake_minimum_required(VERSION 3.15)
project(nagyhazi2)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 98)

add_executable(nagyhazi2 main.cpp jarmu.h Idopont.cpp Idopont.h enums.h lampak.cpp lampak.h erzekelok.cpp erzekelok.h gtest_lite.h memtrace.cpp memtrace.h jarmu.cpp Szimulacio.cpp Szimulacio.h)
