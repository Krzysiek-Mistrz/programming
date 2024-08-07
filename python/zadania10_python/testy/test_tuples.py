#!/usr/bin/python
# -*- coding: utf-8 -*-
import unittest

from tuples import *


class TupleFromNumbersTest(unittest.TestCase):
    def test_numbers_equal(self):
        self.assertTupleEqual(tuple(), tuple_from_numbers(1, 1))

    def test_numbers_unequal(self):
        self.assertTupleEqual((1, 2), tuple_from_numbers(1, 2))


class TupleFromElementsTest(unittest.TestCase):
    def test_less_than_three_elements(self):
        self.assertTupleEqual((None, None, None), tuple_from_elements([]))
        self.assertTupleEqual((None, None, None), tuple_from_elements([1]))
        self.assertTupleEqual((None, None, None), tuple_from_elements([1, 2]))

    def test_at_least_three_elements(self):
        self.assertTupleEqual((1, 2, 3), tuple_from_elements([1, 2, 3]))
        self.assertTupleEqual((1, 2, 3), tuple_from_elements([1, 2, 3, 4]))


class AppendTupleToListTest(unittest.TestCase):
    def test(self):
        self.assertListEqual([1, 2, 3], append_tuple_to_list([1], (2, 3)))
