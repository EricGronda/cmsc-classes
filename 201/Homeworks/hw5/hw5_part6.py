# File: hw5_part6.py
# Author: Eric Gronda
# Date: 10/10/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Calculates average temperatures from a numbr of temperatures

END = "STOP"
################################################################################
# average()   calculates and returns the average
# Input:      numList; a list of floats
# Output:     avgNum; a float, average of list's numbers
def average(numList):
    index = 0
    total = 0
    if(len(numList) > 0):
        while(index <= len(numList) - 1):
            total += numList[index]
            index += 1
        average = total / len(numList)
        return average

def main():
    temp = ""
    tempList = []
    while(temp != END):
        temp = input("Enter a temperature, 'STOP' to exit: ")
        if(temp != END):
            temp = float(temp)
            tempList.append(temp)
    avgTemp = average(tempList)
    print("The average is" , avgTemp)

main()
