# File:        factors.py
# Author:      Eric Gronda
# Date:        11/6/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: 
#    asks for a number, then prints out all of the factors of tha number


def getValidInput(prompt , minn):
    userNum = int(input(prompt))
    validVal = False
    
    while validVal == False:
        validVal = True

        # if value is less that minimum, reprompt
        if userNum <= minn:
            validVal = False
            print("Invalid number.")
            userNum = int(input(prompt))

    return userNum
        
def factors(userNum):
    factors = []

    for i in range(1, userNum + 1):
        if userNum % i == 0:
            factors.append(i)

    return factors

def main():


    # ask for a num
    prompt = "Please enter a number greater than 0: "
    userNum = getValidInput(prompt , 0)

    # find the factors and store into a list
    listFactors = factors(userNum)

    for i in range(len(listFactors)):
        print(listFactors[i])
    


main()
