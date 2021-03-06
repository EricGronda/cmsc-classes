# File:    decoder.py
# Started: by Dr. Gibson
# Author:  Eric Gronda
# Date:    10/16/17
# Section: 06
# E-mail:  gt32930@umbc.edu
# Description:
#   This file contains python code that uses a function to 
#   pull out the uppercase letters from a list of strings
#   to decode a secret message.


######################################################################
# decode() decodes a message by extracting all of the 
#          capital letters to reveal the hidden meaning
# Input:   msgList; a list of strings
# Output:  secret;  a string containing the hidden message
def decode(msgList):
    secret = ""
    indexList = 0

    while(indexList < len(msgList)):
        indexString = 0
        word = msgList[indexList]
       
        while(indexString < len(word)):
            letter = word[indexString]
            if(letter == letter.upper()):
                secret = secret + letter
            indexString += 1
        
        indexList += 1

    return secret



def main():
    # message lists
    msg1 = ["thiS", "lifE", "Cannot", "Really", "bE", "True"]
    msg2 = ["wonDering", "hOw", "Good", "scoreS", "cAn", "regulaRly", \
                "bE", "manaGed", "yOu", "shOuld", "stuDy"]
    msg3 = ["studyinG", "Once", "thrOugh", "miDnight", "wiLl", \
                "caUse", "inComplete", "Knowledge", "Of", "iNformation", \
                "noT", "Helping", "thE", "earnEd", \
                "eXam", "grAde", "iMprove"]

    # calling the decode function for each
    ans1 = decode(msg1)
    ans2 = decode(msg2)
    ans3 = decode(msg3)

    # printing out the secret messages
    print("Message 1's secret was:")
    print(ans1)
    print()

    print("Message 2's secret was:")
    print(ans2)
    print()

    print("Message 3's secret was:")
    print(ans3)
    print()



main()

