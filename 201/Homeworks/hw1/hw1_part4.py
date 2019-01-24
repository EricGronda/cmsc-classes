# File:        hw1_part4.py
# Author:      Eric Gronda
# Date:        9/11/17
# Section:     01
# Description: Asks user for info on car they're buying, then prints out total cost.

car = float(input("How much does the car cost? "))
warranty = float(input("How much does the warranty cost? "))
fees = float(input("How much are the fees? "))
taxes = float(input("How much are the taxes? "))

print("The total cost of the car will be" , car + warranty + fees + taxes)
