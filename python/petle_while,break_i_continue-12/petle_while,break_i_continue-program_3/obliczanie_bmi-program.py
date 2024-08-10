#Program Obliczajacy BMI i Dopasowujacy Odpowiednia Kategorie

weight = float(input("Podaj swoja wage: "))
height = float(input("Podaj swoj wzrost: "))
bmi = weight / (height ** 2)

print("Twoje BMI: " + str(bmi))

if bmi < 18.5:
  print("niedowaga")

elif (bmi >= 18.5) and (bmi < 25):
  print("normalna")

elif (bmi >= 25) and (bmi < 30):
  print("nadwaga")

else:
  print("otylosc")