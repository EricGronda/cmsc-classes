# File: hw5_part1.py
# Author: Eric Gronda
# Date: 10/8/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Asks user for string and letter, then counts how many times that
#              letter appears.
###############################################################################
# numLetter() counts the instances of a letter in a string
# Input:      aString; a string of the phrase to search in
#             letter; a single character to search for
# Output:     none
###############################################################################
def numLetter(aString , letter):
    index = 0
    instances = 0
    aString = aString.lower()
    letter = letter.lower()
    while(index < len(aString) - 1):
        if(letter == aString[index]):
            instances += 1
        index += 1
    return instances
###############################################################################
# main()      executes main program
# Input:      aString; gets string to be used in numLetter()
#             letter; gets letter to be used in numLetter()
#             instances; instances of letter in aString
# Output:     prints how many instances of letter in aString
###############################################################################
def main():
    aString = input("Enter a string: ")
    letter = input("Enter a letter: ")
    instances = numLetter(aString , letter)
    print("There are" , instances , "instances of" , letter , "in the string.")


main()
