# File: hw4_part2.py
# Author: Eric Gronda
# Date: 10/1/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Draw a box

def main():


    width = int(input("Please enter the width of the box: "))
    height = int(input("Please enter the height of the box: "))
    symbolOut = input("Please enter a symbol for the box outline: ")
    symbolIn = input("Please enter a symbol for the box fill: ")

    widthCurrent = 1

#Print Top line

    while(widthCurrent < width):
        print(symbolOut , end="")
        widthCurrent += 1

    print(symbolOut)

#Print middle lines

    heightCurrent = 2
    

    while(heightCurrent < height):
        widthCurrent = 2
        print(symbolOut, end="")
        while(widthCurrent < width):
            print(symbolIn, end="")
            widthCurrent += 1
        print(symbolOut)
        heightCurrent += 1
        

#Print bottom line
    
    if(height > 1):
        widthCurrent = 1
        
        while(widthCurrent < width):
            print(symbolOut , end="")
            widthCurrent += 1

        print(symbolOut)


main()
