# File:        hw3_part1.py
# Author:      Eric Gronda
# Date:        9/24/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Simulates up and down movement of a hailstone

def main():


    height = int(input("Please enter the starting height of the hailstone: "))


    while(height > 1):
        #Height is odd, multiply by 3 and add 1
        if(height % 2 == 1 and height != 1):
            print("Hail is currently at height" , height)
            height = int(height * 3 + 1)
            
        #Height is even, divide by 2
        elif(height % 2 == 0 and height != 0):
            print("Hail is currently at height" , height)
            height = int(height / 2)
    
    #Height is 1 (or 0), end program
    print("Hail stopped at height" , height)



main()
