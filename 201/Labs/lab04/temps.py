# File: temps.py
# Author: Eric Gronda
# Date: 9/25/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Keep track of minimum and maximum temperatures

def main():


    count = 0

    numTemp = int(input("How many temperatures would you like to enter? "))

    while(numTemp <= 0):
        print("You must enter a number greater than zero.")
        numTemp = int(input("How many temperatures would you like to enter? "))
 
    while(count < numTemp):
        temp = float(input("Enter a temperature: "))
        
        if(count == 0):
            minTemp = temp
            maxTemp = temp
        
        count += 1
        
        if(minTemp > temp):
            minTemp = temp
        elif(temp > maxTemp):
            maxTemp = temp

    print("The maximum temperature entered was" , maxTemp)
    print("The minimum temperature entered was" , minTemp)

main()
