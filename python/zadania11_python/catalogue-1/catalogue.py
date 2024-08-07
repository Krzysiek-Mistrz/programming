#!/usr/bin/python
# -*- coding: utf-8 -*-

# Importy
from copy import copy, deepcopy
from typing import Callable, Mapping, Optional

# Definicja klasy Product
class Product:
    # Inicjalizacja obiektu Product
    def __init__(self, id_: str, name: str, price: float) -> None:
        self.id = id_ if id_ is not None else self.generate_id(name)
        self.name = name
        self.price = price
    # Getter dla ceny produktu
    @property
    def price(self) -> float:
        return self.__price
    # Setter dla ceny produktu, ograniczajacy maksymalna cene do 100
    @price.setter
    def price(self, price: float) -> None:
        self.__price = min([price, 100])
    # Metoda do zwracania reprezentacji tekstowej obiektu
    def __str__(self) -> str:
        return '{self.name} [{self.id}] : ${self.price:.2f}'.format(self=self)
    # Metoda porownujaca dwa obiekty Product
    def __eq__(self, other) -> bool:
        return (self.id == other.id) and (self.name == other.name) and (self.price == other.price)
    # metoda do generowania id na podstawie nazwy
    @classmethod
    def generate_id(cls, name: str) -> str:
        return ''.join([c for c in name if c != ' ']) + "_" + str(len(name))

# Definicja klasy Catalogue
class Catalogue:
    # Aliasik
    Inventory = Mapping[str, Product]
    # Inicjalizacja obiektu Catalogue
    def __init__(self, inventory: Inventory = None) -> None:
        self.inventory = deepcopy(inventory) if inventory else {}
    # Metoda dodajaca produkt do katalogu
    def add_product(self, product: Product) -> None:
        self.inventory[product.id] = copy(product)
    # Metoda sprawdzajaca czy produkt o danym id znajduje sie w katalogu
    def __contains__(self, id_: str) -> bool:
        return id_ in self.inventory
    # Metoda zwracajaca produkty spelniajace zadany warunek cenowy
    def get_products_with_appropriate_price(self, predicate: Callable[[float], bool]) -> Inventory:
        return  {k: v for (k, v) in self.inventory.items() if predicate(v.price)}
    # Metoda zwracajaca produkty zawierajace okreslony fragment nazwy
    def get_products_by_name_part(self, chunk: str, ignore_case: bool = False) -> Inventory:
        has_chunk = (lambda name, chunk_: chunk_.lower() in name.lower()) if ignore_case else (lambda name, chunk_: chunk_ in name)
        return {k: v for (k, v) in self.inventory.items() if has_chunk(v.name, chunk)}
