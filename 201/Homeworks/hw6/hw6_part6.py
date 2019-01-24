# File:    hw6_part6.py
# Author:  Eric Gronda
# Date:    11/20/2017
# Section: 06
# E-mail: gt32930@umbc.edu
# Description:
#    Recursively generate the levels of Pascal's triangle

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
# pascal() uses recursion to create each level of Pascal's
#          triangle, reaching the requested height
# Input:   currLevel;    an int, the current level being created
#          levelsToMake; an int, the number of levels requested
#          levelList;    a 2D list of ints, containing the levels
#                                           as they are created
# Output:  None (levelList is changed in place, and the updated
#                levelList will be the same in main() )
def pascal(currLevel , levelsToMake , levelList):
    
    # BASE CASE
    if levelsToMake == 0:
        return None
    # RECURSIVE CASE
    elif levelsToMake > 0:

        # make new row
        levelList.append([1])

        # create new nums
        for i in range(1 , currLevel):
            
            # get column and number
            col = len(levelList[currLevel])

            num = levelList[currLevel - 1][col - 1]
            num += levelList[currLevel - 1][col]

            levelList[currLevel].append(num)

        # end each line with 1
        levelList[currLevel].append(1)

        # call function to create more rows
        pascal(currLevel + 1 , levelsToMake - 1 , levelList)
        
def main():

    # display opening statement
    print("Welcome to the Pascal's triangle generator.")

    # get number of levels to generate
    prompt = ("Please enter the number of levels to generate: ")
    levelsToMake = getValidInput(prompt)

    # generate values in Pascal's triangle
    levelList = [ [1] ]
    pascal(1 , levelsToMake , levelList)
    
    # print out Pascal's triangle
    for i in range( len(levelList) ):
        for j in range( len(levelList[i]) - 1 ):
            print(levelList[i][j] , end=" ")
        print(levelList[i][ len(levelList[i]) - 1 ])

main()
