# File:    fixed_lab09.py
# Author:  Brendan Waters
# Email:   b101@umbc.edu
# Updated by: Dr. Gibson  (k.gibson)
#             Chris Block (christ34)
# Author:  Eric Gronda
# Date:    10/30/17
# Section: 06
# E-mail:  gt32930@umbc.edu
# Description:
#   This file contains python code that is broken and needs
#   to be debugged.


MINN = 1
MAXX = 100

#########################################################
# getValidInt() get an integer within a specified range
# Input:        minn and maxx; two integers
# Output:       num; an integer between minn and maxx
def getValidInt(minn, maxx):
    maxxStr = str(maxx)
    minnStr = str(minn)
    msg = "Enter an integer between " + minnStr + " and " + \
        maxxStr + " (inclusive): "
    num = int(input(msg))
    while num < minn or num > maxx:
        print("Invalid choice!")
        num = int(input(msg))
    return num

############################################################        
# twoInARow() counts the number of duplicates entries
#             next to each other in a list
# Input:      stuff;  a list of any type
# Output:     count; the total number of duplicates found
def twoInARow(stuff):
    resultMsg = "No duplicates next to each other"
    count = 0
    index = 0
    index2 = 1
    while index2 < len(stuff):
        if stuff[index] == stuff[index2]:
            print("Found dupes of", stuff[index], "next to each other.")
            count += 1
        index += 1
        index2 += 1
    return count

###################################################
# equiv() compare two items for equivalence
# Input:  item1 and item2; two items of any type
# Output: resultMsg;       a string of the result
def equiv(item1, item2):
    resultMsg = ""

    if item1 == item2:
        resultMsg = "They match!"
    else:
        resultMsg = "No match"

    return resultMsg

#########################################################
# average() calculates the average of a list of numbers
# Input:    nums; a list of integers or floats
# Output:   avg;  an integer (average of list)
def average(nums):
    index = 0
    total = 0
    while index < len(nums):
        total += nums[index]
        index += 1

    avg = total / len(nums)
    return avg


def main():
    # TEST ONE FUNCTION AT A TIME, AND MAKE SURE IT WORKS
    # BEFORE UNCOMMENTING THE NEXT ONE

    # get a number from the user
    num1 = getValidInt(MINN, MAXX)
    print("Thank you for choosing", num1)

    # check for duplicates next to each other
    numbers = [1, 0, 4, 4, 3, 2, 6, 2, 7, 7, 9]
    result = twoInARow(numbers)
    print("The result of the nearby duplicate test:")
    print("There are", result, "matches")
    
    # check to see if the number from the user is the same as the last
    # number in the list of numbers from before, and print out the answer
    result = equiv(num1, numbers[len(numbers)-1])
    print("The result of the equivalence test:", result)

    # calculate the average of the list
    avg = average(numbers)
    print("The average is", avg)


main()
