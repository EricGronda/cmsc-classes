# File:        hw1_part6.py
# Author:      Eric Gronda
# Date:        9/11/17
# Section:     01
# Description: Asks the user for information about a bill they've received, and calculates      and prints out how much they should pay in total.

bill = float(input("How much was the bill? "))
tax = float(input("How much was the tax percentage? "))
tip = float(input("What percentage do you want to tip? "))

tax = tax / 100
tip = tip / 100


print("The total cost of the meal will be" , bill + (bill * tax) + (bill * tip))
