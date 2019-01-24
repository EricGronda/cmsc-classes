# File:        class.py
# Author:      Eric Gronda
# Date:        9/18/17
# E-mail:      gt32930@umbc.edu
# Description: Offers advice about user's class

def main():


    professor = input("Enter your professor's name: ")

    if professor == "Gibson" or professor == "Neary":
        students = int(input("How many students are in your class? "))

        if students >= 80:
            print("Wow, so many options for study groups!")
        elif students < 80 and students >= 30:
            print("You have so many chances o make new friends!")
        elif students < 30:
            print("You'll get to know all of your classmates really well! :)")

    else:
        print(professor , "doesn't teach CMSC 201! You're in the wrong class!")


main()
