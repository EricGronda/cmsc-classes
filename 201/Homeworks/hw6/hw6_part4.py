# File:    hw6_part4.py
# Author:  Eric Gronda
# Date:    11/15/2017
# Section: 06
# E-mail: gt32930@umbc.edu
# Description:
#    Asks the user for a word, then checks to see if it is a palindrome

########################################################################
# reverseStr() takes in a string and returns the string in reverse
# Input:       word; string to be reversed
# Output:      reverseWord; reversed version of word
def reverseStr(word):
    
    # BASE CASE
    if len(word) == 0:
        return ""

    elif len(word) == 1:
        return word
    # RECURSIVE CASE
    elif len(word) > 1:
        return reverseStr(word[1:]) + word[0]

def main():

    # get word to check for palindrome-ness
    word = input("Please enter a word to check for palindrome-ness: ")

    # check whether the word is a palindrome
    reverseWord = reverseStr(word)
    
    # display results
    if word.lower() == reverseWord.lower():
        print("The word" , word , "IS a palindrome.")
    else:
        print("Sorry, the word" , word , "is NOT a palindrome")
        print("Backwards, it becomes" , reverseWord + ".")
              
main()
