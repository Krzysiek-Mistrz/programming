znak = input("Podaj znak: ")
lancuch = input("Podaj lancuch znakow: ")

def zliczaj(arg_1, arg_2):
  wystapienia = arg_1.count(arg_2)
  return wystapienia

print("Ilosc wystapien: " + zliczaj(lancuch, znak))