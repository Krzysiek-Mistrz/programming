#You're making a voice recognition system. The supported commands are stored in a list. Complete the program to take a command as input, check if it's supported and output "OK" if it is, and "Not supported", if not.

com_list = ["Lights off", "Make coffe", "Lock the door", "Open the door", "Shut down"]

i = input()
b = False

for command in com_list
  if(i == command) 
    b = True
    
if(b == True)
  print("Ok")
 else
   print("Not supported")