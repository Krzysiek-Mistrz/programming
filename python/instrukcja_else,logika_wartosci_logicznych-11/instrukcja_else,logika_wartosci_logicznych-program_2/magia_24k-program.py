#Program Realizujacy Sprawdzenie Czystosci Zlota

czystosc = float(input("PODAJ CZYSTOSC ZLOTA: "))

if czystosc >= 99.99 and czystosc <= 100:
    print("24K")

elif czystosc < 99.99 and czystosc >= 91.7:
    print("22K")

elif czystosc < 91.7 and czystosc >= 83.3:
    print("20K")

elif czystosc < 83.3 and czystosc >= 75:
    print("18K")

else:
    print("16K")