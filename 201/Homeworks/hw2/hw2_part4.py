# File:        hw2_part4.py
# Author:      Eric Gronda
# Date:        9/17/17
# Section:     06
# E-mail:      gt32930@umbc.edu
# Description: Simple calculator using two integers

def main():


    print("You can do many operations with this program:")
    print("add, subtract, multiply, divide,")
    print("int divide, mod, and exponents")
    
    operation = input("Which operation do you want to perform? ")
    num1 = int(input("Enter the first number of the operation: "))
    num2 = int(input("Enter the second number of the operation: "))

    if (operation == "add"):
        answer = num1 + num2
        operation = "+"
        print(num1 , operation , num2 , "=" , answer)

    elif (operation == "subtract"):
        answer = num1 - num2
        operation = "-"
        print(num1 , operation , num2 , "=" , answer)

    elif (operation == "multiply"):
        answer = num1 * num2
        operation = "*"
        print(num1 , operation , num2 , "=" , answer)

    elif (operation == "divide"):
        answer = num1 / num2
        operation = "/"
        print(num1 , operation , num2 , "=" , answer)

    elif (operation == "int divide"):
        answer = num1 // num2
        operation = "//"
        print(num1 , operation , num2 , "=" , answer)

    elif (operation == "mod"):
        answer = num1 % num2
        operation = "%"
        print(num1 , operation , num2 , "=" , answer)

    elif (operation == "exponents"):
        answer = num1 ** num2
        operation = "**"
        print(num1 , operation , num2 , "=" , answer)

    else:
        print("Invalid operation")


main()
