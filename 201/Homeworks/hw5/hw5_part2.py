# File: hw5_part2.py
# Author: Eric Gronda
# Date: 10/8/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Searches through a phrase and looks ofr occurrences of a word

################################################################################
# inPhrase()      searches through string to find instances of a word
# Input:          phrase; string to search through
#                 word; word to search for in phrase
# Output:         None
################################################################################
def inPhrase(phrase , word):
    lowWord = word.lower()
    lowPhrase = phrase.lower()

    indexStart = 0
    indexEnd = len(word)
    instances = 0

    while(indexEnd <= len(phrase)):
        if(lowWord == lowPhrase[indexStart : indexEnd]):
            print("Found" , word , "at index" , indexStart)
            instances += 1
        indexStart += 1
        indexEnd += 1

    print("Found" , word , "a total of" , instances , "times")

################################################################################
def main():
    phrase = input("Please enter a phrase: ")
    word = input("Please enter a word to search for: ")

    validWord = False
    while(validWord == False):
        validWord = True
       
        if(len(word) > len(phrase)):
            validWord = False
            print("The word cannot be longer than the phrase.")
            word = input("Please enter a word to search for: ")    
    
    inPhrase(phrase , word)
main()
