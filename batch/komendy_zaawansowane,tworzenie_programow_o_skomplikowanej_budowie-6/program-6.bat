@echo off
title PROGRAM
@chcp 852
set nazwa_programu="Prosty program napisany w języku Batch"
echo --------------------------------------------------------------------------------------
echo Ja jestem %nazwaprogramu%.
echo --------------------------------------------------------------------------------------
echo Wpisz swoje imie:
echo.
set /p imie=">> "
echo Witaj %imie%
echo --------------------------------------------------------------------------------------
ping 1.1.1.1 -n 1 -w 705 > nul
echo PARAMETRY TEGO DNIA: %time% ; %date%
timeout /t 7.5>nul
echo --------------------------------------------------------------------------------------
echo.
echo KONIEC DZIALANIA
echo.
echo --------------------------------------------------------------------------------------
pause
exit