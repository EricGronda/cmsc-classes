# File:        hw3_part5.py
# Author:      Eric Gronda
# Date:        9/26/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Prints numbers 1 through 77 with special cases

def main():

    num = 1

    while(num <= 77):

        if(num % 4 == 0 and num % 5 == 0):
            print("The year 2020 is coming soon!")
        elif(num % 4 == 0 and  num % 5 != 0):
            print("Four leaf clovers are lucky!")
        elif(num % 4 != 0 and num % 5 == 0):
            print("Where do you see yourself in five years?")
        else:
            print(num)

        num += 1
        


main()
