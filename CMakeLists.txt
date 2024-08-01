cmake_minimum_required(VERSION 3.5.0)
project(MazeGenerator VERSION 0.1.0 LANGUAGES C)

file(GLOB_RECURSE SOURCES
    src/headers/*.h
    src/impl/*.c
    src/main.c
)

add_executable(MazeGenerator ${SOURCES})
target_include_directories(MazeGenerator
PRIVATE
src/headers/
)