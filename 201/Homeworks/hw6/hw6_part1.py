# File:    hw6_part1.py
# Author:  Eric Gronda
# Date:    11/14/2017
# Section: 06
# E-mail: gt32930@umbc.edu
# Description:
#    Calculates the summation of a number, stopping at a specified number

###########################################################################
# summ()  performs the summation of one number down to another number
# Input:  sumFrom; a number to do the summation from
#         sumTo; a number to do the summation to
# Output: summation; the summation of the first number to the second number
def summ(sumFrom , sumTo):
    
    # BASE CASE
    if sumFrom == sumTo:
        return sumTo
    
    # RECURSIVE CASE
    elif sumFrom > sumTo:
        return summ(sumFrom - 1 , sumTo) + sumFrom

def main():

    # get numbers to sum from and to sum down to
    sumFrom = int(input("Please input the number you want to sum from: "))
    sumTo = int(input("Please input the number you want to sum down to: "))
    
    # do the summation of the first number to the second
    summation = summ(sumFrom , sumTo)
    
    # print out results
    results = "The summation from " + str(sumFrom) + " to "
    results +=  str(sumTo) + " is " + str(summation)
    print(results)

main()
