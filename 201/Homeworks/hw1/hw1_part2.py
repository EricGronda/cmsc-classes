# File:        hw1_part2.py
# Author:      Eric Gronda
# Date:        9/11/17
# Section:     01
# Description: Asks for information about how much your bill was, how many people are in your party, and calculates and prints out the amount each person needs to pay

bill = float(input("How much was your total bill? "))
people = int(input("How many people are in your dining party? "))

print("Each person needs to pay $" , bill / people)
