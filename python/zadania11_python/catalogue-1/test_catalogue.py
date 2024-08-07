#!/usr/bin/python
# -*- coding: utf-8 -*-

import unittest

from catalogue import Product, Catalogue


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
