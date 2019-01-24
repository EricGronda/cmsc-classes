# File:    hw6_part2.py
# Author:  Eric Gronda
# Date:    11/14/2017
# Section: 06
# E-mail: gt32930@umbc.edu
# Description:
#    Recursively draw a right triangle given height and symbols

############################################################################
# recurTri() creates a right triangle using a height and a symbol
# Input:     height; height of the created right triangle
#            symbol; symbol to be used when drawing the triangle
# Output:    None
def recurTri(height , symbol):

    # BASE CASE
    if height == 0:
        return None

    elif height == 1:
        print(symbol)
        return None

    # RECURSIVE CASE    
    elif height > 1:
        # continue recursion
        recurTri(height - 1 , symbol)

        # create line of symbols
        for i in range(height - 1):
            print(symbol , end="")
        # create end of line
        print(symbol)


def main():

    # get height of triangle and symbol to draw it with
    height = int(input("Please enter the height of the triangle: "))
    symbol = input("Please enter the symbol to use: ")

    # generate and print triangle
    recurTri(height , symbol)

main()

