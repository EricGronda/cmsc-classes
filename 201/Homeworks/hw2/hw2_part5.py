# File:        hw2_part5.py
# Author:      Eric Gronda
# Date:        9/17/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Plays a simple game where computer guesses dog breed

def main():


    print("Please enter 'yes' or 'no' to these questions.")

    tail = input("Does your dog have a curly tail? ")
    if (tail == "yes"):

        bark = input("Does your dog bark? ")
        if (bark == "yes"):
            breed = "Eurasier!"
        elif (bark == "no"):
            breed = "Basenji!"

    elif (tail == "no"):

        ears = input("Do the dog's ears stick up? ")
        if (ears == "yes"):
            breed = "Pharaoh Hound!"
        elif (ears == "no"):
            
            color = input("Does the dog come in multiple colors? ")
            if (color == "yes"):
                breed = "Chesapeake Bay Retriever!"
            elif (color == "no"):
                breed = "Maremma Sheepdog!"

    print("Your dog is a" , breed)


main()
