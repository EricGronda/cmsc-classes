# File: languages.py
# Author: Eric Gronda
# Date: 10/2/17
# Section: 06
# E-mail: gt32930@umbc.edu
# Description: Displays different options for programming languages


def main():


#Programming language options:
    
    languages = ["Python" , "Java" , "C++" , "Ruby" , "C" , "PHP" , "Shakespeare"]

#Display Options
    
    count = 0
    
    while count < len(languages):
        print((count + 1) , "-" , languages[count])
        count += 1

#Get user vote
    
    vote = int(input("What language do you like? "))

    SENTINEL = 0

    votes = [0 , 0 , 0 , 0 , 0 , 0 , 0]

    while vote != SENTINEL:

        if(vote > 7 or vote < 0):
            vote = int(input("What language do you like? "))
        else:
            votes[(vote - 1)] += 1
            vote = int(input("What language do you like? "))        

#Print results

    index = 0

    while index < len(languages):
        print(languages[index] , "has" , votes[index] , "votes.")
        index += 1


main()
