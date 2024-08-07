#!/usr/bin/python
# -*- coding: utf-8 -*-
import unittest

from lists import *


class IsElementOnListTest(unittest.TestCase):
    def test_element_is_on_list(self):
        self.assertTrue(is_element_on_list([1, 2], 1))

    def test_element_is_not_on_list(self):
        self.assertFalse(is_element_on_list([1, 2], 3))


class ElementXorTest(unittest.TestCase):
    def test_e1_is_not_e2_is_not(self):
        self.assertFalse(element_xor([1, 2], 3, 4))

    def test_e1_is_not_e2_is(self):
        self.assertFalse(element_xor([1, 2], 3, 1))

    def test_e1_is_e2_is_not(self):
        self.assertTrue(element_xor([1, 2], 1, 3))

    def test_e1_is_e2_is(self):
        self.assertFalse(element_xor([1, 2], 1, 2))


class ArgConditionTest(unittest.TestCase):
    def test_is_list_with_at_most_two_elements(self):
        self.assertFalse(arg_condition([1, 2]))

    def test_is_list_with_more_than_two_elements(self):
        self.assertTrue(arg_condition([1, 2, 3]))

    def test_is_none(self):
        self.assertTrue(arg_condition(None))


class ListCondition1Test(unittest.TestCase):
    def test_at_least_two_elements_and_second_equals_5(self):
        self.assertTrue(list_condition_1([0, 5]))

    def test_at_least_two_elements_but_second_not_equals_5(self):
        self.assertFalse(list_condition_1([0, 6]))

    def test_less_than_two_elements(self):
        self.assertFalse(list_condition_1([0]))


class ListCondition2Test(unittest.TestCase):
    def test_two_to_three_elements_and_penultimate_equals_3(self):
        self.assertTrue(list_condition_2([3, 0]))
        self.assertTrue(list_condition_2([0, 3, 0]))
        self.assertTrue(list_condition_2([0, 0, 3, 0]))

    def test_two_to_three_elements_but_penultimate_not_equals_3(self):
        self.assertFalse(list_condition_2([1, 0]))
        self.assertFalse(list_condition_2([0, 1, 0]))
        self.assertFalse(list_condition_2([0, 0, 1, 0]))

    def test_number_of_elements_out_of_range(self):
        self.assertFalse(list_condition_2([0]))
        self.assertFalse(list_condition_2(5 * [0]))


class RemoveFirstThreeElementsTest(unittest.TestCase):
    def test_at_most_three_elements(self):
        lst = []
        remove_first_three_elements(lst)
        self.assertListEqual([], lst)

        lst = [0]
        remove_first_three_elements(lst)
        self.assertListEqual([], lst)

        lst = [0, 0]
        remove_first_three_elements(lst)
        self.assertListEqual([], lst)

        lst = [0, 0, 0]
        remove_first_three_elements(lst)
        self.assertListEqual([], lst)

    def test_more_than_three_elements(self):
        lst = 3 * [0] + [1]
        remove_first_three_elements(lst)
        self.assertListEqual([1], lst)


class ReplaceLastTwoElementsTest(unittest.TestCase):
    def test_has_at_least_two_elements(self):
        lst = [1, 2]
        lst_ret = replace_last_two_elements(lst)
        self.assertListEqual([1, 2], lst)
        self.assertListEqual([9], lst_ret)

    def test_has_less_than_two_elements(self):
        lst = [1]
        lst_ret = replace_last_two_elements(lst)
        self.assertListEqual([1], lst)
        self.assertListEqual([1], lst_ret)
        self.assertIsNot(lst, lst_ret)


class MergeEndsTest(unittest.TestCase):
    def test_at_least_four_elements(self):
        self.assertListEqual([1, 2, 3, 4], merge_ends([1, 2, 3, 4]))
        self.assertListEqual([1, 2, 4, 5], merge_ends([1, 2, 3, 4, 5]))

    def test_one_to_three_elements(self):
        self.assertListEqual([1, 1], merge_ends([1, 2, 3]))
        self.assertListEqual([1, 1], merge_ends([1]))

    def test_no_elements(self):
        self.assertListEqual([], merge_ends([]))
        self.assertListEqual([], merge_ends(None))


class RemoveElementIfExists(unittest.TestCase):
    def test_element_exists(self):
        lst = [1, 2]
        lst_ret = remove_element_if_exists(lst, 2)
        self.assertListEqual([1], lst_ret)
        self.assertListEqual([1, 2], lst)

    def test_element_does_not_exist(self):
        lst = [1, 2]
        lst_ret = remove_element_if_exists(lst, 3)
        self.assertListEqual([1, 2], lst_ret)
        self.assertListEqual([1, 2], lst)
        self.assertIsNot(lst, lst_ret)


class IsPalindromeTest(unittest.TestCase):
    def test(self):
        self.assertFalse(is_palindrome('abc'))
        self.assertTrue(is_palindrome('kayak'))
