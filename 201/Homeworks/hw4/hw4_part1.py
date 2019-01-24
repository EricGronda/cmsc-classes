# File: hw4_part1.py
# Author: Eric Gronda
# Date: 10/1/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Create a modulus table

def main():


    modNum = int(input("Please enter the number to mod by: "))
    highNum = int(input("Please enter how high you'd like to go: "))

    answers = []

    count = 0

    while(count <= highNum):
        answers.append(count)
        numFinal = answers[count] % modNum
        print(count , "%" , modNum , "=" , numFinal)
        count += 1


main()
