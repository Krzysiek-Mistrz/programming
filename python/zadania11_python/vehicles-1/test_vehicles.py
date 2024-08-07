#!/usr/bin/python
# -*- coding: utf-8 -*-

import unittest

from vehicles import *


class TestCar(unittest.TestCase):
    def test_max_speed(self):
        car = Car(id_="", brand="", engine_hp=100.0)

        self.assertEqual(100.0, car.max_speed())


class TestBicycle(unittest.TestCase):
    def test_max_speed(self):
        bike = Bicycle(id_="", brand="", n_gears=8)

        self.assertEqual(24, bike.max_speed())


class TestVehicle(unittest.TestCase):
    def test_str(self):
        car = Car(id_="KR 00001", brand="Toyota", engine_hp=100.0)

        self.assertEqual("KR 00001 :  Toyota", str(car))


if __name__ == '__main__':
    unittest.main()
