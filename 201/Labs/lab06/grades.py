# File:        grades.py
# Started:     by Brianna Richardson (& Dr. Gibson)
# Author:      Eric Gronda
# Date:        10/9/2017
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: This file contains python code that uses functions to allow 
#              a user to get information about a list of grades entered.

MIN_VAL = 0
MAX_VAL = 100
SENTINEL = -1

###################################################################
# printList() prints out a list, showing the index of each element
# Input:      theList; a list of any types of variables
# Output:     None
def printList(theList):
    index = 0
    while(index < len(theList)):
        print("At index" , index , "there is a" , theList[index])
        index += 1
    
###########################################################
# printMin() prints the minimum value in a list of numbers
# Input:     theList; a list of integers and/or floats
# Output:    None
def printMin(theList):
    index = 0
    minGrade = theList[0]
    
    while(index < len(theList) - 1):
        if(theList[index] < minGrade):
            minGrade = theList[index]
        index += 1
    print("The minimum is" , minGrade)

###########################################################
# printMax() prints the minimum value in a list of numbers
# Input:     theList; a list of integers and/or floats
# Output:    None
def printMax(theList):
    index = 0
    maxGrade = theList[0]

    while(index < len(theList) - 1):
        if(theList[index] > maxGrade):
            maxGrade = theList[index]
        index += 1
    print("The maximum is" , maxGrade)


def main():
    gradeList = []
    msg = "Enter a grade (" + str(SENTINEL) + " to quit): "

    grade = int(input(msg))

    # ask the user for grades until they choose to exit
    while(grade != SENTINEL):
        # check beforehand, so we only save valid grades
        if grade >= MIN_VAL and grade <= MAX_VAL:
            gradeList.append(grade)
        else:
            print("\tThe grade", grade, "is invalid")
            print("\tGrades must be between", MIN_VAL, "and", MAX_VAL)

        grade = int(input(msg))

    # call the print function
    printList(gradeList)

    # print out the minimum and maximum values
    printMin(gradeList)
    printMax(gradeList)

main()
