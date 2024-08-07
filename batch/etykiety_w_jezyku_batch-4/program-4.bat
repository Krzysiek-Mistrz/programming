@echo off
echo POLECANE STRONY INTERNETOWE
echo ---------------------------------------------------------------------------------------------------------------------
:tekst
cls
echo [1] - Wikibooks
echo [2] - Wikipedia
echo [3] - Pliki wsadowe w Wikibooks
echo [4] - Pliki wsadowe w Wikipedii
echo ---------------------------------------------------------------------------------------------------------------------
:zapytanie
set /p odp=PODAJ NUMER STRONY DO URUCHOMIENIA (Q ABY WYJSC, T ABY POWTORZYC)
if %odp%=="q" goto wyjscie
if %odp%=="t" goto tekst
if %odp%=="1" start "chrome.exe http://pl.wikibooks.org"
if %odp%=="2" start "chrome.exe http://pl.wikipedia.org"
if %odp%=="3" start "chrome.exe http://pl.wikibooks.org/Pliki_wsadowe"
if %odp%=="4" start "chrome.exe http://pl.wikipedia.org/Program_wsadowy"
if not %odp%=="q" goto tekst
if not %odp%=="t" goto tekst
if not %odp%=="1" goto tekst
if not %odp%=="2" goto tekst
if not %odp%=="3" goto tekst
if not %odp%=="4" goto tekst
goto zapytanie
:wyjscie