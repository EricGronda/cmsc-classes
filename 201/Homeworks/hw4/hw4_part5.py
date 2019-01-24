# File: hw4_part5.py
# Author: Eric Gronda
# Date: 10/3/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Checks validity of user's PIN


#CHECK FOR ZEROS, DON'T REMOVE THEM!!!!


def main():


#Get Pin and Account info

    pinPrompt = "Please enter a pin: "
    pinNum = input(pinPrompt)

    accountPrompt = "Please enter the account type (c, d, or s): "
    accountType = input(accountPrompt)

    validPin = False

#Phrases

    shortC = "is too short for a checking account."
    longC = "is too long for a checking account."
    shortD = "is too short for a debit account."
    longD = "is too long for a debit account."
    shortS = "is too short for a savings account."
    longS = "is too long for a savings account."

    endZero = "ends in a zero."
    leadZero = "starts with a zero."

#Check account type
    
    #Checking and Debit

    if(accountType == "c" or accountType == "d"):
        
        #4 digits
        while(validPin == False):
            validPin = True
            
            #Less than 4
            if(len(pinNum) < 4):
                validPin = False
                
                #Credit Statement
                if(accountType == "c"):
                    print("The PIN" , pinNum , shortC)
                
                #Debit Statement
                elif(accountType == "d"):
                    print("The PIN" , pinNum , shortD)

            #Greater than 4
            elif(len(pinNum) > 4):
                validPin = False

                #Credit Statement
                if(accountType == "c"):
                    print("The PIN" , pinNum , longC)

                #Debit Statement
                elif(accountType == "d"):
                    print("The PIN" , pinNum , longD)

            #Leading zeros
            if(pinNum[0 : 0] == "0"):
                validPin = False
                print("The PIN" , pinNum , leadZero)

            #Ends in zero
            elif(pinNum[ : (len(pinNum) - 1)] == "0"):
                validPin = False
                print("The PIN" , pinNum , endZero)

            #Get new input if validPin is False
            if(validPin == False):
               pinNum = input(pinPrompt)
               accountType = input(accountPrompt)
          
    #Savings
    if(accountType == "s"):
        
        while(validPin == False):
            validPin = True

            #Less than 3 digits
            if(len(pinNum) < 3):
                validPin = False
                print("The PIN" , pinNum , shortS)
            
            #More than 3 digits
            elif(len(pinNum) > 3):
                validPin = False
                print("The PIN" , pinNum , longS)

            #Leading zeros
            if(pinNum[0 : 0] == "0"):
                validPin = False
                print("The PIN" , pinNum , leadZero)

            #Repeating Numbers
            #Check if pin worth checking (has three digits)
            if(validPin == True):
                
                #First digit same as second digit; Second same as third
                if(pinNum[0] == pinNum[1] or pinNum[1] == pinNum[2]):
                    validPin = False
                    print("The PIN" , pinNum , "has repeating numbers.")

            #Prompt New input
            if(validPin == False):
                pinNum = input(pinPrompt)
                accountType = input(accountPrompt)

    #Print Final Output
    print("Thank you for picking the pin" , pinNum , "for your account.")



            

main()
