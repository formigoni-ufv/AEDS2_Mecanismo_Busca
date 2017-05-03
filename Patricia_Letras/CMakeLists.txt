cmake_minimum_required(VERSION 3.7)
project(TP_1)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c patricia.c patricia.h auxprocedures.c auxprocedures.h)
add_executable(TP_1 ${SOURCE_FILES})