# File:        hw1_part8.py
# Author:      Eric Gronda
# Date:        9/11/17
# Section:     01
# Description: Asks the user for information about how many items of food they want to buy at a fixed prie, and calculates and prints out the total cost of a meal.

def main():

    appCost = 9.5
    mainCost = 15.8
    dessCost = 6.55

    appNum = int(input("How many appetizers? "))
    mainNum = int(input("How many main dishes? "))
    dessNum = int(input("How many desserts? "))

    total = (appCost * appNum) + (mainCost * mainNum) + (dessCost * dessNum)

    print("Your total cost is" , total)

main()
