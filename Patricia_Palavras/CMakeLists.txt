cmake_minimum_required(VERSION 3.7)
project(Patricia_Palavras)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c auxprocedures.c patricia.c)
add_executable(Patricia_Palavras ${SOURCE_FILES})