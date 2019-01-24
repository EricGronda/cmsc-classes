# File:        hw3_part3.py
# Author:      Eric Gronda
# Date:        9/26/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: User enters time int the order of hours, minutes, time period


def main():

    
    hourBad = False
    minuteBad = False
    timePeriodBad = False

    #Initial Prompt

    print("Please enter the time: hours, then minutes, then AM/PM")    

    # Hour Section

    hour = int(input("Please enter the hour: "))    

    while(hourBad == False):
        hourBad = True
        
        if(hour <= 0):
            print("The hours value is too low.")
            hourBad = False
            hour = int(input("Please enter the hour: "))
        elif(hour > 12):
            print("The hours value is too high.")
            hourBad = False
            hour = int(input("Please enter the hour: "))

    # Minute Section

    minute = int(input("Please enter the minute: "))

    while(minuteBad == False):
        minuteBad = True

        if(minute <= 0 or minute >= 60):
            minuteBad = False

            if(minute <= 0):
                print("The minutes value is too low")
            if(minute >= 60):
                print("The minutes value is too high")

            minute = int(input("Please enter the minute: "))

    #Time Period Section

    timePeriod = input("Please enter the time period: ")

    while(timePeriodBad == False):
        timePeriodBad = True
        
        if(timePeriod != "AM" and timePeriod != "PM"):
            timePeriodBad = False
            print("Time period must be 'AM' or 'PM'")
            timePeriod = input("Please enter the time period: ")

    # Print end time

    print("It is" , hour , ":" , minute , timePeriod)


main()
