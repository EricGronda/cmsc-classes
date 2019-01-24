# File:        hw3_part2.py
# Author:      Eric Gronda
# Date:        9/24/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Calculate exponentiation without exponentiation

def main():


    num = int(input("Please enter the first number: "))
    exp = int(input("Please enter the second number: "))
    count = 0
    numExp = 1

    #While loop numExp by num1 for num2 times
    while(count < exp):
        numExp *= num
        count += 1

    print(num , "**" , exp , "=" , numExp )


main()
