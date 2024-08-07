#!/usr/bin/python
# -*- coding: utf-8 -*-

import unittest

from catalogue import Product


class TestProduct(unittest.TestCase):
    def test_init(self):
        product = Product(id_="RB01", name="Robot", price=10.2)
        self.assertEqual("RB01", product.id)
        self.assertEqual("Robot", product.name)
        self.assertEqual(10.2, product.price)

    def test_str_integer_price(self):
        product = Product(id_="RB01", name="Robot", price=10)
        self.assertEqual("Robot [RB01] : $10.00", str(product))

    def test_str_fractional_price(self):
        product = Product(id_="RB01", name="Robot", price=10.2)
        self.assertEqual("Robot [RB01] : $10.20", str(product))

    def test_eq(self):
        self.assertEqual(Product(id_="P1", name="", price=0), Product(id_="P1", name="", price=0))
        self.assertNotEqual(Product(id_="P1", name="X", price=0), Product(id_="P1", name="", price=0))

    def test_generate_id(self):
        self.assertEqual("X1_2", Product.generate_id("X1"))
        self.assertEqual("AB_3", Product.generate_id("A B"))

    def test_init_no_id(self):
        product = Product(id_=None, name="Robot", price=10.2)
        self.assertEqual("Robot_5", product.id)
        self.assertEqual("Robot", product.name)
        self.assertEqual(10.2, product.price)


class TestProductOptional(unittest.TestCase):
    def test_too_high_price(self):
        product = Product(id_="RB01", name="Robot", price=200)
        self.assertEqual(100, product.price)


if __name__ == '__main__':
    unittest.main()
