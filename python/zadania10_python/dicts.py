#!/usr/bin/python
# -*- coding: utf-8 -*-

#
# TEMAT: Słowniki
#
# -----------------------------------------------------------------------------

from typing import Dict, Any, List, Tuple, Optional, Set

def dict_intro() -> None:
    people_scores = {'Adam': 2, 'Bogdan': 4, 'Cezary': 1}
    for person, score in people_scores.items():
        print(f"{person} = {score}")

# Alias `Menu` na typ `Dict[str, float]` poprawia czytelność kodu
# oraz upraszcza wprowadzanie ewentualnych zmian w programie.
Menu = Dict[str, float]

def update_price(menu: Dict[str, float], dish: str) -> None:
    if dish in menu:
        menu[dish] += 50

def fix_key(dct: Dict[str, Any], incorrect_key: str, correct_key: str) -> Dict[str, Any]:
    corrected_dct = dct.copy()
    if incorrect_key in corrected_dct:
        corrected_dct[correct_key] = corrected_dct.pop(incorrect_key)
    return corrected_dct

def update_all_prices(menu: Menu) -> None:
    for dish in menu:
        menu[dish] += 50

ClassRegister = Dict[str, List[float]]

def average_grades_1(register: ClassRegister) -> Dict[str, float]:
    return {name: sum(grades) / float(len(grades)) for name, grades in register.items()}

# [OPT]
def average_grades_2(register: ClassRegister) -> Dict[str, Optional[float]]:
    averages = {}
    for student, grades in register.items():
        if grades:
            avg_grade = sum(grades) / len(grades)
            averages[student] = avg_grade
        else:
            averages[student] = None
    return averages

def letters_frequencies(s: str) -> Dict[str, int]:
    frequencies = {}
    for letter in s:
        frequencies[letter] = frequencies.get(letter, 0) + 1
    return frequencies

def letters_frequency_2(s: str) -> Tuple[Dict[str, int], int]:
    frequencies = letters_frequencies(s)
    unique_letters = len(frequencies)
    return frequencies, unique_letters

def census(register: Dict[str, Dict[str, Any]]) -> Tuple[Dict[str, int], float]:
    country_counts = {}
    total_age = 0
    total_persons = 0
    for person in register.values():
        country = person['address']['country']
        age = person['age']
        country_counts[country] = country_counts.get(country, 0) + 1
        total_age += age
        total_persons += 1
    average_age = total_age / total_persons
    return country_counts, average_age

# lista zakupowa - mapowanie nazwy produktu na liczbę sztuk (do kupienia)
ShoppingList = Dict[str, int]

def sum_shopping_lists(list1: ShoppingList, list2: ShoppingList) -> ShoppingList:
    combined_list = list1.copy()
    for item, quantity in list2.items():
        if item in combined_list:
            combined_list[item] += quantity
        else:
            combined_list[item] = quantity
    return combined_list

def sum_shopping_lists_nonempty(list1: ShoppingList, list2: ShoppingList) -> ShoppingList:
    combined_list = sum_shopping_lists(list1, list2)
    combined_list_nonempty = {item: quantity for item, quantity in combined_list.items() if quantity > 0}
    return combined_list_nonempty

def filter_pesels_by_name_initial(persons: Dict[str, str], name_initial: str) -> Set[str]:
    return {pesel for pesel, name in persons.items() if name.startswith(name_initial)}