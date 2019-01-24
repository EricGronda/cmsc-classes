# File:        hw2_part7.py
# Author:      Eric Gronda
# Date:        9/17/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Ask user about two switches to determine state of generator

def main():


    print("Please enter 'y' for yes and 'n' for no.")

    switch1 = input("Is the first switch on? (y/n) ")
    switch2 = input("Is the second switch on? (y/n) ")

    if (switch1 == switch2):
        print("The generator is off.")
    else:
        print("The generator is on.")


main()
