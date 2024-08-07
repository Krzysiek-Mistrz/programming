cmake_minimum_required(VERSION 3.13)

set(PROJECT_ID catalogue)

set(SOURCE_FILES
        src/catalogue.cpp
        )

set(SOURCES_FILES_TESTS
        test/test_catalogue.cpp
        test/test_product.cpp
        )

include(../SetCommonConfig.cmake)
