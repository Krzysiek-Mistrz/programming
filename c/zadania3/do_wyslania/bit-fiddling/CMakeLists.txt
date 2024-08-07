cmake_minimum_required(VERSION 3.13)

set(PROJECT_ID bit_fiddling)

set(SOURCE_FILES
        src/bitlib.c
        )

set(SOURCES_FILES_TESTS
        test/test_bitlib.cpp
        )

include(../SetCommonConfig.cmake)
