# File: hw5_part4.py
# Author: Eric Gronda
# Date: 10/10/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Gets a number and checks the properties of it

################################################################################
# checkOddOrEven()    check if number is odd or even
# Input:              userNum; an integer
# Output:             None
def checkOddOrEven(userNum):
    if(userNum % 2 == 0):
        print(userNum , "is even")
    else:
        print(userNum , "is odd")

################################################################################
# checkPositive()     check if number is negative, positive, or zero
# Input:              userNum; an integer
# Output:             None
def checkPositive(userNum):
    if(userNum > 0):
        print(userNum , "is positive")
    elif(userNum < 0):
        print(userNum , "is negative")
    elif(userNum == 0):
        print(userNum , "is zero")

################################################################################
# checkDivisible()    check if the number is divisible by a second number
# Input:              userNum; an integer
# Output:             None
def checkDivisible(userNum):
    divNum = int(input("Enter the number you would like to check: "))
    if(userNum % divNum == 0):
        print(userNum , "is divisible by" , divNum)
    else:
        print(userNum , "is not divisible by" , divNum)

def main():
    userNum = int(input("Enter the number you would like to check: "))
    checkOddOrEven(userNum)
    checkPositive(userNum)
    checkDivisible(userNum)

main()
