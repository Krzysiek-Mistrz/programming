wart_feet = float(input("Podaj wartosc w feet: "))

def convert(arg_1):
  inches = arg_1 * 12
  return inches

print("wartosc w inches: " + convert(wart_feet))