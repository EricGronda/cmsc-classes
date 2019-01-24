# File:    hailstone.py
# Started: by Dr. Gibson
# Author:  Eric Gronda
# Date:    11/13/17
# Section: 06
# E-mail:  gt32930@umbc.edu
# Description:
#   This file contains python code that implements the
#   "flight" of a hailstone, following the HOTPO rules
#   (also known as the Collatz Conjecture), recursively

# NO CONSTANTS NEEDED, THE NUMBERS USED IN flight() ARE
#    PART OF A FORMULA/MATHEMATICAL CONJECTURE

############################################################
# flight() recursively calculates the path of a hailstone
# Input:   the height of the hailstone
# Output:  a recursive call, which at the end returns 
#          the number of "steps" taken for the
#          hailstone to reach a height of 1
def flight(height):

    #### BASE CASES:
    # print out an "invalid" message and return 0
    if height < 1:
        print("Invalid height of" , str(height))
        return 0

    # stops when it reachs height of 1 (the ground)
    elif height == 1:
        print("Height of" , int(height))
        return 0

    #### RECURSIVE CASES:
    # if the current height is even, divide it by 2
    if height % 2 == 0:
        print("Height of" , int(height))
        return flight(height / 2) + 1

    # if the current height is odd, multiply it by 3, then add 1
    elif height % 2 != 0:
        print("Height of" , int(height))
        return flight((height * 3) + 1) + 1

def main():

    print("Welcome to the Hailstone Simulator!")
    msg = "Please enter a height for the hailstone to start at: "
    startHeight = int(input(msg))

    # recursive call goes here
    steps = flight(startHeight)

    print("\nIt took", steps, "steps to hit the ground.")

    print("Thank you for using the Hailstone Simulator!\n")

main()

    

