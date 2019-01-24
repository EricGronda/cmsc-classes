# File:        hw2_part6.py
# Author:      Eric Gronda
# Date:        9/17/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Simplified day of the week calculator

def main():


    date = int(input("Please enter the day of the month: "))
    
    if (date <= 0) or (date > 30):
        print("The date" , date , "is an invalid day.")

    else:

        #Mod day by 7; use remainder to find day of week
    
        date = date % 7

        if (date == 1):
            day = "Friday!"
        elif (date == 2):
            day = "Saturday!"
        elif (date == 3):
            day = "Sunday!"
        elif (date == 4):
            day = "Monday!"
        elif (date == 5):
            day = "Tuesday!"
        elif (date == 6):
            day = "Wednesday!"
        elif (date == 7):
            day = "Thursday!"

        print("Today is a" , day)


main()
