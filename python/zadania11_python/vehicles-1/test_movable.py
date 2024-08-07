#!/usr/bin/python
# -*- coding: utf-8 -*-

import unittest

from vehicles import *


class TestMovable(unittest.TestCase):
    def test_init(self):
        movable = Movable(x=1, y=2)
        self.assertEqual(1, movable.x)
        self.assertEqual(2, movable.y)

    def test_move(self):
        movable = Movable(x=0, y=0)
        movable.move(dx=1, dy=2)
        self.assertEqual(1, movable.x)
        self.assertEqual(2, movable.y)


class TestVehicleWithMovableMixin(unittest.TestCase):
    def test_inheritance(self):
        self.assertTrue(issubclass(Vehicle, Movable))


if __name__ == '__main__':
    unittest.main()
