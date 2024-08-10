#Program obliczajacy rok przestepny na podstawie danych od uzytkownika

print("PROGRAM OBLICZAJACY ROK PRZESTEPNY \n")
print("================================== \n")

rok = int(input("Podaj rok: "))

if rok % 100 == 0:
   print("rok nie jest przestepny")

else:
   if rok % 4 == 0:

      if rok % 400 == 0:
         print("rok jest przestepny")

      else:
         print("rok nie jest przestepny")

   else:
      print("rok nie jest przestepny")