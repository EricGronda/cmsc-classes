# File:        food.py
# Author:      Eric Gronda
# Date:        9/18/17
# E-mail:      gt32930@umbc.edu
# Description: Asks the user about their breakfast and gives opinions

def main():


    food = input("Please enter what you ate for breakfast: ")

    if food == "green eggs" or food == "ham":
        print("Excellent choice!")
    else:
        print(food , "is a strange choice for breakfast.")


main()
