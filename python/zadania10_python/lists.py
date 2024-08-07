#!/usr/bin/python
# -*- coding: utf-8 -*-

#
# TEMAT: Listy
#
# -----------------------------------------------------------------------------

from typing import List, Any, Optional

def is_element_on_list(lst: List[Any], e: Any) -> bool:
    if e in lst:
        return True
    else:
        return False

def element_xor(lst: List[Any], e1: Any, e2: Any) -> bool:
    return (e1 in lst) and (e2 not in lst)

def print_every_second_elem(lst: List[str]) -> None:
    for i in range(len(lst)):
        if i % 2 != 0:
            continue
        print(f"{i} -> {lst[i]}")

def arg_condition(arg: Optional[List[Any]]) -> bool:
    return arg is None or (isinstance(arg, list) and len(arg) > 2)

def list_condition_1(lst: List[int]) -> bool:
    return len(lst) >= 2 and lst[1] == 5

def list_condition_2(lst: List[int]) -> bool:
    return len(lst) >= 2 and len(lst) <= 4 and lst[-2] == 3

def remove_first_three_elements(lst: List[Any]) -> None:
    lst[:] = lst[3:]

def replace_last_two_elements(lst: List[int]) -> List[int]:
    if len(lst) >= 2:
        return lst[:-2] + [9]
    else:
        return lst[:]

def merge_ends(lst: Optional[List[Any]] = None) -> List[Any]:
    if lst is None or len(lst) == 0:
        return []
    elif len(lst) >= 4:
        return lst[:2] + lst[-2:]
    else:
        return [lst[0]] * 2

def remove_element_if_exists(lst: List[Any], e: Any) -> List[Any]:
    lst_copy = lst.copy()
    if e in lst_copy:
        lst_copy.remove(e)
    return lst_copy

def is_palindrome(s: str) -> bool:
    for i in range(len(s)):
        if s[i] != s[-i - 1]:
            return False
    return True
