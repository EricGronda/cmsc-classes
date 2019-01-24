# File:    hw6_part5.py
# Author:  Eric Gronda
# Date:    11/18/2017
# Section: 06
# E-mail: gt32930@umbc.edu
# Description:
#    Non-Recursively generate the levels of Pascal's triangle

########################################################################
# getValidInput() verifies that an int entered is greater than zero
# Input:          num; an int to validate
# Output:         num; a validated integer
def getValidInput(prompt):
    
    num = int(input(prompt))
    
    # use boolean flag to verify number
    validNum = False
    while validNum == False:
        validNum = True
        
        # reprompt if the number is less than 0
        if num <= 0:
            validNum = False
            print("Your number must be positive (greater than zero).")
            num = int(input(prompt))

    return num

########################################################################
# pascal() creates each level of Pascal's
#          triangle, reaching the requested height
# Input:   levelsToMake; an int, the number of levels requested
# Output:  None (the levels are printed from the function)
def pascal(levelsToMake):
    
    # print the first and second levels
    print("1")
    print("1 1")

    # make 2D List of levels
    levelList = [ [1 ,1] ]

    # until all levels are printed
    for level in range(1 , levelsToMake):
        levelList.append([1])

        # until all numbers in level are created
        for pascNums in range(level):
            
            # create new number
            col = len(levelList[level])
            num = levelList[level - 1][col - 1] 
            num += levelList[level - 1][col]

            # append new number to the list
            levelList[level].append(num)
        
        # end level with 1
        levelList[level].append(1)
            
        # print out level of numbers
        for j in range(len(levelList[level]) - 1):
            print(levelList[level][j] , end=" ")
        print(levelList[level][len(levelList[level]) - 1])

def main():

    # display opening statement
    print("Welcome to the Pascal's triangle generator.")

    # get number of levels to generate
    prompt = ("Please enter the number of levels to generate: ")
    levelsToMake = getValidInput(prompt)

    # display Pascal's triangle
    pascal(levelsToMake)
              
main()
