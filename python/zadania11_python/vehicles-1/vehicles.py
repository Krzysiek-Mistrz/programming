#!/usr/bin/python
# -*- coding: utf-8 -*-

from abc import ABC, abstractmethod
from typing import TypeVar, Container

# klasa Movable
class Movable:
    # inicjalizacja obiektu Movable
    def __init__(self, x: float, y: float, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.x = x
        self.y = y
    # metoda do przemieszczania obiektu
    def move(self, dx: float, dy: float):
        self.x += dx
        self.y += dy

# klasa abstrakcyjna Vehicle, dziedziczy po ABC i Movable
class Vehicle(ABC, Movable):
    # inicjalizacja obiektu Vehicle
    def __init__(self, id_: str, brand: str, *args, **kwargs) -> None:
        super().__init__(0, 0, *args, **kwargs)
        self.id = id_
        self.brand = brand
    # metoda abstrakcyjna do zwracania maksymalnej predkosci
    @abstractmethod
    def max_speed(self) -> float:
        raise NotImplementedError()
    # metoda do zwracania reprezentacji tekstowej obiektu
    def __str__(self) -> str:
        return '{self.id} :  {self.brand}'.format(self=self)

# klasa Car, dziedziczy po Vehicle
class Car(Vehicle):
    # inicjalizacja obiektu Car
    def __init__(self, id_: str, brand: str, engine_hp: float, *args, **kwargs) -> None:
        super().__init__(id_, brand, *args, **kwargs)
        self.engine_hp = engine_hp
    # metoda do zwracania maksymalnej predkosci samochodu
    def max_speed(self) -> float:
        return self.engine_hp

# klasa Bicycle, dziedziczy po Vehicle
class Bicycle(Vehicle):
    # inicjalizacja obiektu Bicycle
    def __init__(self, id_: str, brand: str, n_gears: int, *args, **kwargs) -> None:
        super().__init__(id_, brand, *args, **kwargs)
        self.n_gears = n_gears
    # metoda do zwracania maksymalnej predkosci roweru
    def max_speed(self) -> float:
        return self.n_gears * 3

V = TypeVar('V', bound = Vehicle)

# funkcja vehicle_collection_as_string
def vehicle_collection_as_string(vehicles: Container[V]):
    return '\n'.join(map(str, vehicles))

# funkcja compute_min_travel_duration
def compute_min_travel_duration(distance: float, vehicle: Vehicle) -> float:
    return distance / vehicle.max_speed()

# funkcja compute_min_travel_duration_as_string
def compute_min_travel_duration_as_string(distance: float, vehicle: Vehicle) -> str:
    return '{0:.3f} h'.format(compute_min_travel_duration(distance, vehicle))
