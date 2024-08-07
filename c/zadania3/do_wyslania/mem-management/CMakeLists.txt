cmake_minimum_required(VERSION 3.13)
set(PROJECT_ID memory_management)

set(SOURCE_FILES
        src/mymem.c
        )

set(SOURCES_FILES_TESTS
        test/test_mymem.cpp
        )

include(../SetCommonConfig.cmake)
