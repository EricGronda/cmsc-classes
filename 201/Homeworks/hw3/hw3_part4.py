# File:        hw3_part4.py
# Author:      Eric Gronda
# Date:        9/26/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Calculates money raised at a charity run

def main():


    numDonate = int(input("How many pledges did you secure? "))
    count = 0
    pledgeTotal = 0

    while(count < numDonate):
        count += 1
        print("For pledge #" , count)

        pledgeNew = float(input("How much money was pledged? "))
        pledgeTotal += pledgeNew

    miles = float(input("How many miles did you run for your charity? "))
    totalEarned = miles * pledgeTotal

    print("Based on your" , miles , "miles you earned $" , totalEarned ,
          "for the charity.")


main()
