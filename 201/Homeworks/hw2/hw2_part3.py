# File:        hw2_part3.py
# Author:      Eric Gronda
# Date:        9/17/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Simulates a simple deli order

def main():


#Gather Data
    print("Choose 'ham', 'cheese', or 'veggie' for your sandwich")
    sandwich = input("Please choose a sandwich: ")

    print("Choose 'cookies', 'chips', or 'pickle' for your side")
    side = input("Please choose a side: ")

    print("Choose 'water', 'lemonade', or 'soda' for your drink")
    drink = input("Please choose a drink: ")

    
#Sandwich Type
    if (sandwich == "ham") or (sandwich == "cheese") or (sandwich == "veggie"):
        print("You choose a" , sandwich , "for your sandwich.")
    else:
        print("A" , sandwich , "is not a proper choice for a sandwich.")

#Side Type
    if (side == "cookies") or (side == "chips") or (side == "pickle"):
        print("You choose a" , side , "for your side.")
    else:
        print("A" , side , "is not a proper side dish.")

#Drink type
    if (drink == "water") or (drink == "lemonade") or (drink == "soda"):
        print("You choose a" , drink , "for your drink.")
    else:
        print("A" , drink , "is not a proper drink.")

#End Statement
    print("Enjoy your meal!")


main()
