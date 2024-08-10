text = input("Podaj fraze oddzielona spacjami: ")
word = input("Podaj pojedyncze slowo lub znak: ")

def search(arg_1, arg_2):
  appear = arg_1.count(arg_2)
  if appear > 0:
    print("Word found")
  else:
    print("Word not found")
    
search(text, word)