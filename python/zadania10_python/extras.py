#!/usr/bin/python
# -*- coding: utf-8 -*-

#
# TEMAT: Zagadnienia dodatkowe
#
# -----------------------------------------------------------------------------

from typing import List, Set, Dict, Tuple, Optional, Callable

def get_unique_letters(s: str) -> Set[str]:
    return set(list(s)) if len(s) >= 3 else set()

# lista zakupowa - mapowanie nazwy produktu na liczbę sztuk (do kupienia)
ShoppingList = Dict[str, int]

def products_to_buy(list1: ShoppingList, list2: ShoppingList) -> Set[str]:
    return set(list1.keys()) | set(list2.keys())

def products_only_on_one_list(list1: ShoppingList, list2: ShoppingList) -> int:
    return len(set(list1.keys()) ^ set(list2.keys()))

def two_dice_rolls_combinations() -> Dict[int, Set[Tuple[int, int]]]:
    results = {}
    for i in range(1, 7):
        for j in range(1, 7):
            sum_ = i + j
            if sum_ not in results:
                results[sum_] = set()
            results[sum_].add((i, j))
    return results

def append_and_sort(lst: List[str]) -> List[str]:
    new_lst = lst.copy()
    new_lst.append('abc')
    return sorted(new_lst)