# Program Obliczajacy Sume Z Cen Biletow

suma_cen = 0
i = 1

while i <= 5:

  wiek = int(input("Podaj wiek " + str(i) + " pasazera: "))
  i += 1

  if wiek < 3:
    continue

  else:
    suma_cen += 100

print("Suma cen biletow: " + str(suma_cen))