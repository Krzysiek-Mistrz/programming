#!/usr/bin/python
# -*- coding: utf-8 -*-

import unittest

# from catalogue import Product, Catalogue
from catalogue import Product, Catalogue, InventoryOverflowException


class TestCatalogue(unittest.TestCase):
    def test_init(self):
        p = Product(id_="P", name="", price=0)
        inventory = {p.id: p}
        c = Catalogue(inventory)
        del inventory[p.id]

        self.assertEqual(1, len(c.inventory))

    def test_add_product(self):
        p = Product(id_="P", name="X", price=0)
        c = Catalogue()
        c.add_product(p)
        p.name = "Y"

        self.assertEqual("X", c.inventory["P"].name)

    def test_contains_key_is_not_present(self):
        c = Catalogue()

        self.assertFalse("K" in c)

    def test_contains_key_is_present(self):
        p = Product(id_="P", name="", price=0)
        c = Catalogue()
        c.add_product(p)

        self.assertTrue(p.id in c)

    def test_inventory_overflow_add_product(self):
        p1 = Product(id_="P1", name="", price=0)
        p2 = Product(id_="P2", name="", price=0)
        p3 = Product(id_="P3", name="", price=0)
        c = Catalogue()
        c.add_product(p1)
        c.add_product(p2)
        with self.assertRaises(InventoryOverflowException):
            c.add_product(p3)

    def test_inventory_overflow_init(self):
        p1 = Product(id_="P1", name="", price=0)
        p2 = Product(id_="P2", name="", price=0)
        p3 = Product(id_="P3", name="", price=0)
        with self.assertRaises(InventoryOverflowException):
            Catalogue({p1.id: p1, p2.id: p2, p3.id: p3})

    def test_add_too_many_products_in_a_batch(self):
        p1 = Product(id_="P1", name="", price=0)
        p2 = Product(id_="P2", name="", price=0)
        p3 = Product(id_="P3", name="", price=0)
        c = Catalogue()
        self.assertEqual(2, c.add_products([p1, p2, p3]))

        self.assertDictEqual({p1.id: p1, p2.id: p2}, c.inventory)


class TestCatalogueFiltering(unittest.TestCase):
    def test_get_products_with_appropriate_price(self):
        p1 = Product(id_="X1", name="Toy X1", price=10.3)
        p2 = Product(id_="X2", name="Toy X2", price=8.3)
        c = Catalogue({p1.id: p1, p2.id: p2})
        filtered_products = c.get_products_with_appropriate_price(lambda price: price < 10.0)

        self.assertDictEqual({p2.id: p2}, filtered_products)

    def test_get_products_by_name_part_case_sensitive(self):
        p1 = Product(id_="X1", name="TOY uppercase", price=10)
        p2 = Product(id_="X2", name="toy lowercase", price=10)
        c = Catalogue({p1.id: p1, p2.id: p2})
        filtered_products = c.get_products_by_name_part("toy")

        self.assertDictEqual({p2.id: p2}, filtered_products)

    def test_get_products_by_name_part_case_insensitive(self):
        p1 = Product(id_="X1", name="TOY uppercase", price=10)
        p2 = Product(id_="X2", name="toy lowercase", price=10)
        c = Catalogue({p1.id: p1, p2.id: p2})
        filtered_products = c.get_products_by_name_part("toy", ignore_case=True)

        self.assertDictEqual(c.inventory, filtered_products)


if __name__ == '__main__':
    unittest.main()
