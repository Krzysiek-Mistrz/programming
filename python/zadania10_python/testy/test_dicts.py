#!/usr/bin/python
# -*- coding: utf-8 -*-
import unittest

from dicts import *


class DictsTest(unittest.TestCase):
    def test_update_price(self):
        menu = {"egg": 10, "fish": 30}
        update_price(menu, "egg")
        self.assertDictEqual({"egg": 60, "fish": 30}, menu)

    def test_fix_key_all_correct(self):
        dct = {"x": 1, "y": 2}
        dct_ret = fix_key(dct, incorrect_key='z', correct_key='x')
        self.assertDictEqual({"x": 1, "y": 2}, dct_ret)
        self.assertIsNot(dct_ret, dct)

    def test_fix_key_needs_correction(self):
        dct = {"x": 1, "y": 2}
        dct_ret = fix_key({"x": 1, "y": 2}, incorrect_key='y', correct_key='z')
        self.assertDictEqual({"x": 1, "z": 2}, dct_ret)
        self.assertIsNot(dct_ret, dct)

    def test_update_all_prices(self):
        menu = {"egg": 10, "fish": 30}
        update_all_prices(menu)
        self.assertDictEqual({"egg": 60, "fish": 80}, menu)

    def test_average_grades_1(self):
        register = {"Ann": [3.0, 4.0, 5.0], "Bob": [2.0, 5.0]}
        self.assertDictEqual({"Ann": 4.0, "Bob": 3.5}, average_grades_1(register))

    def test_average_grades_2(self):
        register = {"Ann": [3.0, 4.0, 5.0], "Bob": []}
        self.assertDictEqual({"Ann": 4.0, "Bob": None}, average_grades_2(register))

    def test_letters_frequencies(self):
        self.assertDictEqual({'a': 2, 'l': 1}, letters_frequencies('ala'))

    def test_letters_frequencies_2(self):
        self.assertTupleEqual(({'a': 2, 'l': 1}, 2), letters_frequency_2('ala'))

    def test_census(self):
        register = {
            'John': {'address': {'country': 'USA'}, 'age': 20},
            'Bob': {'address': {'country': 'USA'}, 'age': 30},
            'Ann': {'address': {'country': 'UK'}, 'age': 40},
        }
        self.assertTupleEqual(({'USA': 2, 'UK': 1}, 30), census(register))

    def test_sum_shopping_lists(self):
        list1 = {"apple": 0, "orange": 5, "eggs": 1}
        list2 = {"banana": 3, "apple": 0, "orange": 4}
        self.assertDictEqual({"banana": 3, "apple": 0, "orange": 9, "eggs": 1},
                             sum_shopping_lists(list1, list2))

    def test_sum_shopping_lists_nonempty(self):
        list1 = {"apple": 0, "orange": 5, "eggs": 1}
        list2 = {"banana": 3, "apple": 0, "orange": 4}
        self.assertDictEqual({"banana": 3, "orange": 9, "eggs": 1},
                             sum_shopping_lists_nonempty(list1, list2))


class FilterPeselsByNameInitialTest(unittest.TestCase):
    def test_no_name_with_given_initial(self):
        people = {
            "0": "Adam Abacki",
            "1": "Bogdan Babacki"
        }
        self.assertSetEqual(set(), filter_pesels_by_name_initial(people, 'C'))

    def test_one_name_with_given_initial(self):
        people = {
            "0": "Adam Abacki",
            "1": "Bogdan Babacki"
        }
        self.assertSetEqual({'0'}, filter_pesels_by_name_initial(people, 'A'))

    def test_multiple_names_with_given_initial(self):
        people = {
            "0": "Adam Abacki",
            "1": "Bogdan Babacki",
            "2": "Alfred Abacki"
        }
        pesels = filter_pesels_by_name_initial(people, 'A')
        self.assertSetEqual({'0', '2'}, pesels)
