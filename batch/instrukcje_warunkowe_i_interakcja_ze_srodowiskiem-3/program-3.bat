@echo off
echo POLECANE STRONY INTERNETOWE
echo -----------------------------------------------------------------------------------------------------------
echo [1] - Wikibooks
echo [2] - Wikipedia
echo [3] - Pliki wsadowe w Wikibooks
echo [4] - Pliki wsadowe w Wikipedii
echo -----------------------------------------------------------------------------------------------------------
echo PODAJ NUMER STRONY DO URUCHOMIENIA

set /p odp=
if %odp%=="1" start "chrome.exe http://pl.wikibooks.org"
if %odp%=="2" start "chrome.exe http://pl.wikipedia.org"
if %odp%=="3" start "chrome.exe http://pl.wikibooks.org/Pliki_wsadowe"
if %odp%=="4" start "chrome.exe http://pl.wikibooks.org/Program_wsadowy"
if not %odp%=="1" exit
if not %odp%=="2" exit
if not %odp%=="3" exit
if not %odp%=="4" exit