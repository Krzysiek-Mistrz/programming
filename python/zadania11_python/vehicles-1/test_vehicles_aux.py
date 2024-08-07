#!/usr/bin/python
# -*- coding: utf-8 -*-

import unittest

from vehicles import *


class TestVehicleAux(unittest.TestCase):
    def test_compute_min_travel_duration(self):
        car = Car(id_="", brand="", engine_hp=100.0)
        bike = Bicycle(id_="", brand="", n_gears=8)
        distance = 50
        self.assertAlmostEqual(distance / car.max_speed(), compute_min_travel_duration(distance, car), 10 ** (-8))
        self.assertAlmostEqual(distance / bike.max_speed(), compute_min_travel_duration(distance, bike), 10 ** (-8))

    def test_compute_min_travel_duration_as_string(self):
        car = Car(id_="", brand="", engine_hp=100.0)
        bike = Bicycle(id_="", brand="", n_gears=8)
        distance = 50
        self.assertEqual("0.500 h", compute_min_travel_duration_as_string(distance, car))
        self.assertEqual("2.083 h", compute_min_travel_duration_as_string(distance, bike))

    def test_vehicle_collection_as_string(self):
        car = Car(id_="C1", brand="", engine_hp=100.0)
        bike = Bicycle(id_="B1", brand="", n_gears=8)
        self.assertEqual(str(car) + '\n' + str(bike), vehicle_collection_as_string([car, bike]))


if __name__ == '__main__':
    unittest.main()
