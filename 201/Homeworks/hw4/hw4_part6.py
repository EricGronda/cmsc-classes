#File: hw4_part6.py
#Author: Eric Gronda
#Date: 10/06/17
#Section: 06
#E-mail: gt32930@umbc.edu
#Description: Create a task list to remind the user of what to do and how
#             much time is left to do it


END = "END"

def main():


    taskList = []
    hoursLeft = []

    task = ""

    while(task != END):
        task = input("Please enter a task, or 'END' to stop: ")
        taskList.append(task)

        if(task != END):
            time = input("Please enter the hour(s) needed to complete: ")
            hoursLeft.append(time)

    index = 0
    print("\nHere is your task list: ")

    while(index < (len(taskList) - 1)):
        print(hoursLeft[index] , "hours to complete:" , taskList[index])
        index += 1


main()
