#File: hw4_part7.py
#Author: Eric Gronda
#Date: 10/6/17
#Section: 06
#E-mail: gt32930@umbc.edu
#Description: Create a grocery list that prevents duplication


STOP = "STOP"

def main():


    groceries = []

    item = input("Please enter a grocery item ('STOP' to exit): ")

    while(item != STOP):
        
        
        length = len(groceries)
        count = 0
        
        if(item != groceries[count]):
            groceries.append(item)
            count += 1

        item = input("Please enter a grocery item ('STOP' to exit): ")
#        while(count < length):
 #           if(item != groceries[count]):
  #              groceries.append(item)
   #         elif(item == groceries[count]):
    ##            print("Error: The item" , item , "is already in the list.")
      ##          groceries.remove(item)
        #    count += 1
    
    print("There are" , length , "groceries in your list:")
    
    index = 0

    while(index < length):
        print(groceries[index])
        index += 1

main()
