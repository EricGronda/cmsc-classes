# File:        hw3_part7.py
# Author:      Eric Gronda
# Date:        9/28/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Draw a right triangle wiht equal width and height

def main():


# Gather variables

    height = int(input("Please enter the height of your triangle: "))
    symbol = input("Please enter a single character for the symbol: ")

# Idea: Print a symbol, add 1 to number of symbols, repeat until
# height is reached

    width = 0

    heightCurrent = 0
    widthCurrent = 0

#First symbol, because loop of end=""

    if(height > 0):
        print(symbol)
        heightCurrent += 1
        width +=1

#Print symbol, extend WidthCurrent until equal to width, then new line

        while(heightCurrent < height):

            while(widthCurrent < width):
                print(symbol, end="")
                widthCurrent += 1

            print(symbol)
            widthCurrent = 0
            width += 1
            heightCurrent += 1

main()
