#!/bin/bash
gpio -g mode 26 up
#odczytanie stanu logicznego przycisku
gpio -g read 26
#zatrzymanie sie do chwili nacisniecia przycisku
gpio -g wfi 26 falling
