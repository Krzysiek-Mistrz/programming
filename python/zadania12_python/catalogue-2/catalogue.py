#!/usr/bin/python
# -*- coding: utf-8 -*-


from copy import copy, deepcopy
from typing import Callable, Mapping, Optional, Iterable


class Product:
    max_name_len = 20

    def __init__(self, id_: Optional[str], name: str, price: float) -> None:
        self.id = id_ if id_ is not None else self.generate_id(name)
        self.name = name
        self.price = price

    #dodanie gettera do 'atrybutu' name (za pom dekoratora)
    @property
    def name(self) -> str:
        return self.__name

    @property
    def price(self) -> float:
        return self.__price

    #dodanie settera do 'atrybutu' name (za pom dekoratora)
    @name.setter
    def name(self, name: str) -> None:
        if len(name) > self.max_name_len:
            raise ValueError(f"Name too long ({len(name)} chars)")
        self.__name = name

    @price.setter
    def price(self, price: float) -> None:
        self.__price = min([price, 100])

    def __str__(self) -> str:
        return '{self.name} [{self.id}] : ${self.price:.2f}'.format(self=self)

    def __eq__(self, other) -> bool:
        return (self.id == other.id) and (self.name == other.name) and (self.price == other.price)

    @classmethod
    def generate_id(cls, name: str) -> str:
        """Wygeneruj ID zgodnie z regułą: usuń spacje i dodaj na koniec liczbę wszystkich znaków w nazwie.
        """
        return ''.join([c for c in name if c != ' ']) + '_' + str(len(name))


#dodanie nowego wyjatku
class InventoryOverflowException(Exception):
    pass


class Catalogue:
    Inventory = Mapping[str, Product]
    #dodanie nowego max pojemnosci inventory
    max_inventory_size = 2

    #dodanie metody klasowej sprawdzajacej czy pojemnosc zostala osiagnieta
    @classmethod
    def assert_inventory_has_capacity(cls, inventory: Inventory, about_to_insert: bool = False) -> None:
        if inventory and len(inventory) > cls.max_inventory_size - int(about_to_insert):
            raise InventoryOverflowException

    def __init__(self, inventory: Inventory = None) -> None:
        self.assert_inventory_has_capacity(inventory)
        self.inventory = deepcopy(inventory) if inventory else {}

    def add_product(self, product: Product) -> None:
        self.assert_inventory_has_capacity(self.inventory, about_to_insert=True)
        self.inventory[product.id] = copy(product)

    def __contains__(self, id_: str) -> bool:
        return id_ in self.inventory

    def get_products_with_appropriate_price(self, predicate: Callable[[float], bool]) -> Inventory:
        return {k: v for (k, v) in self.inventory.items() if predicate(v.price)}

    def get_products_by_name_part(self, chunk: str, ignore_case: bool = False) -> Inventory:
        has_chunk = (lambda name, chunk_: chunk_.lower() in name.lower()) if ignore_case \
            else (lambda name, chunk_: chunk_ in name)
        return {k: v for (k, v) in self.inventory.items() if has_chunk(v.name, chunk)}

    #dodanie funkcji dodajecej wiele produktow
    def add_products(self, products: Iterable[Product]) -> int:
        n_products_added = 0
        for product in products:
            try:
                self.add_product(product)
            except InventoryOverflowException:
                print(f"Error when adding product: {product}\n" "   Reason: inventory overflow")
                break
            n_products_added += 1
        return n_products_added