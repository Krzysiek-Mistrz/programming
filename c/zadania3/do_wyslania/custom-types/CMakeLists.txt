cmake_minimum_required(VERSION 3.13)

set(PROJECT_ID custom_types)

set(SOURCE_FILES
        src/tasks.c
        )

set(SOURCES_FILES_TESTS
        test/test_tasks.cpp
        )

include(../SetCommonConfig.cmake)
