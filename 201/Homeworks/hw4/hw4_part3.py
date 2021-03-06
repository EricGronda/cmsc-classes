# File: hw4_part3.py
# Author: Eric Gronda
# Date: 10/3/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: User enrolls students in course

STOP = "QUIT"



def main():


    students = []
    msg = "Please enter a student name ('QUIT' to stop): "
    name = input(msg)
    CLASS = 8

    while(name != STOP):
        students.append(name)
        name = input(msg)

    print("There are" , len(students) , "enrolled in this course.")

    if(len(students) < CLASS):
        print("This class is under enrolled!")
    elif(len(students) > CLASS):
        print("This class is over enrolled!")
    elif(len(students) == CLASS):
        print("This class is perfectly enrolled!")


main()
