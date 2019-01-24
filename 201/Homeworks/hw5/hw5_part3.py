# File: hw5_part3.py
# Author: Eric Gronda
# Date: 10/8/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Checks grammar of a sentence (start capital, end punctuation)

END = ""

################################################################################
# checkCapital()   checks for a capital letter at the start of a sentence
# Input:           sentence; sentence being searched for a capital letter
# Output:          None
def checkCapital(sentence):
    if(sentence[0] == sentence[0].upper()):
        print("Correct capitalization!")
    else:
        print("WRONG - Sentences start with a capital letter.")

################################################################################
# checkPunctuation()  checks for punctuation at end of sentence
# Input:              sentence; sentence being searched for puntation
# Output:             None
def checkPunctuation(sentence):
    listPunc = ["?" , "!" , "."]
    index = 0
    goodPunc = "Correct Punctuation!"
    if(sentence[len(sentence) - 1] == listPunc[0]):
        print(goodPunc)
    elif(sentence[len(sentence) - 1] == listPunc[1]):
        print(goodPunc)
    elif(sentence[len(sentence) - 1] == listPunc[2]):
        print(goodPunc)
    else:
        print("WRONG - Sentences use punctuation.")

def main():
    sentence = "placeholder"
    while(sentence != END):
        sentence = input("Enter a sentence (enter nothing to quit): ")
        if(sentence != END):
            checkCapital(sentence)
            checkPunctuation(sentence)

main()
