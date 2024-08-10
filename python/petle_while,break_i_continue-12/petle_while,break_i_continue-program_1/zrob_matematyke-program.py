suma = 0

while True:
  liczba = float(input("Podaj liczbe: "))

  suma += liczba

  print("twoja suma wynosi: " + str(suma) + "\n")
  interakcja_2 = input("Czy chcesz zakonczyc program? Napisz \'stop\' jezeli chcesz")

  if interakcja_2 == "stop":
    break