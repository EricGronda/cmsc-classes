# File:        hw3_part6.py
# Author:      Eric Gronda
# Date:        9/26/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Output a "counting" box

def main():


    width = int(input("Please enter a width: "))
    height = int(input("Please enter a height: "))
    count = 1
    num = 0

    area = width * height

    while(num < area):
        num += 1
        if(count < width):
            print(num , end = " ")
            count += 1
        elif(count >= width):
            print(num)
            count = 1
                  

main()
