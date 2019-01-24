# File:        hw2_part2.py
# Author:      Eric Gronda
# Date:        9/17/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Asks user for a number, then rounds it up or down.

def main():


    number = float(input("Input the number you are rounding: "))
    rounding = input("Do you want to round up or down? ")
    print("Original value:" , number)

    if(float(number) == int(number)):
        number = int(number)

    else:

        if (rounding == "down"):
            print("Rounding down...")
            number = int(number // 1)

        elif (rounding == "up"):        
            print("Rounding up...")
            number = int((number + 1) // 1)

        else:
            print("Invalid command...")
            
    print("Rounded value:" , number)


main()
