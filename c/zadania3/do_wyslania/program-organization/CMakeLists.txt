cmake_minimum_required(VERSION 3.13)

project(program_organization)

set(PROJECT_ID program_organization)

# UWAGI:
#
# *) Bieżącym katalogiem dla tego pliku CMakeLists.txt jest główny katalog
#     projektu - to istotne podczas podawania względnych ścieżek do plików.
#
# *) Definiując listy ścieżek do plików musisz jawnie podać każdy pojedynczy
#      plik - nie możesz wskazać od razu całego folderu.[1]
#
# *) Poszczególne elementy w liście rozdzielamy dowolną kombinacją znaków
#      białych (tj. spacji, tabulatorów i znaków nowej linii), ale NIE
#      przecinkami (czy innymi znakami drukowanymi).
#    Przykład #1 - oddzielanie spacjami: set(SOURCE_FILES plik1.c plik2.c)
#    Przykład #2 - oddzielanie znakami nowej linii (i spacjami):
#      set(SOURCE_FILES
#           plik1.c
#           plik2.c
#           )
#
# [1] Technicznie jest to możliwe (zob. file - GLOB:
#       https://cmake.org/cmake/help/latest/command/file.html#glob|]]),
#       jednak to zła praktyka, o czym informuje dokumentacja narzędzia CMake.

set(SOURCE_FILES
        src/mylib.c
        )

set(SOURCES_FILES_TESTS
        test/test_mylib.cpp
        )

include(../SetCommonConfig.cmake)