# File:    scramble.py
# Started: by Dr. Gibson (updated by Kristin McLaughlin)
# Author:  Eric Gronda
# Date:    12/4/17
# Section: 06
# E-mail:  gt32930@umbc.edu
# Description:
#   This file contains python code that computes all of 
#   the possible combinations of a string's characters.

########################################################################
# permute() is a recursive function that scrambles a string
# Input:    currentScramble; the scrambled word so far
#           lettersLeft;     the letters left to scramble
# Output:   None;            prints out each scramble as it's completed
def permute(currentScramble, lettersLeft):

    # BASE CASE: no letters are left
    if len(lettersLeft) == 0:
        # print out the currentScramble variable to see the result
        print(currentScramble)

    # RECURSIVE CASE: 
    else:

        # for each letter still available for scrambling
        for i in range(len(lettersLeft)):
            letter = lettersLeft[i]

            # create a copy of the string without that letter
            # (this code removes the FIRST instance of the letter)
            # (for example: if string was "2010", now it's "210")
            newLettersLeft = lettersLeft.replace(letter, "", 1)

            # add the letter we removed from lettersLeft
            # to the current scrambled word, call it newScramble
            newScramble = currentScramble + letter

            # RECURSIVE CALL: use the new variables for this call
            # permute() takes in currentScramble, lettersLeft
            permute(newScramble , newLettersLeft)

def main():

    print("Welcome to the Scrambler!")
    word = input("Please enter a string to scramble: ")

    # call the recursive function here
    # permute() takes in currentScramble, lettersLeft
    permute("" , word)

    print("Thank you for using the Scrambler!\n")

main()

    

