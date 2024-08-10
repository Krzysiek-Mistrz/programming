#Program Biletowy Zawierajacy Dane Siedzen

seats = [
        ['a', 'b', 'c'],
        ['d', 'e', 'f'],
        ['g', 'h', 'i'],
        ['j', 'k', 'l'],
        ]

row = int(input("Podaj Odpowiedni Wiersz: "))
column = int(input("Podaj Odpowiednia Kolumne: "))
print(seats[row][column])