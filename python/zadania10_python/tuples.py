#!/usr/bin/python
# -*- coding: utf-8 -*-

#
# TEMAT: Krotki
#
# -----------------------------------------------------------------------------

from typing import List, Any, Tuple, Union


def tuple_from_numbers(a: int, b: int) -> Union[Tuple[()], Tuple[int, int]]:
    if a == b:
        return ()
    else:
        return (a, b)

def tuple_from_elements(lst: List[int]) -> Union[Tuple[int, ...], Tuple[None, ...]]:
    if len(lst) >= 3:
        return tuple(lst[:3])
    else:
        return (None, None, None)

def append_tuple_to_list(lst: List[Any], tpl: Tuple[Any, Any]) -> List[Any]:
    lst.extend(tpl)
    return lst