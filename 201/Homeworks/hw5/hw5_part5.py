# File: hw5_part5.py
# Author: Eric Gronda
# Date: 10/10/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Gets a list and prints them out in reverse order

################################################################################
# backwards()    reverses a string and prints the result
# Input:         forString; a string to reverse
# Output:        None
def backwards(forString):
    #idea: start at forString[len(forString) - 1] and iterate backwards
    indexList = len(forString) - 1
    #Iterate backwards over the list by words
    while(indexList >= 0):
        print("The string '" + forString[indexList] + "' reversed is" , end=" '")
        #Separate by word
        word = forString[indexList]
        indexWord = len(word) - 1
        #Iterate backwards by letter
        while(indexWord >= 0):
            if indexWord > 0:
                print(word[indexWord] , end = "")
            else:
                print(word[indexWord] + "'")
            indexWord -= 1
        indexList -= 1

def main():
    numWords = int(input("How many words would you like to turn backwards? "))
    count = 1
    listWords = []
    while(count <= numWords):
        word = input("Please enter string #" + str(count) + ": ")
        listWords.append(word)
        count += 1
    backwards(listWords)

main()
