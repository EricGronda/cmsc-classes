# File:    doggo.py
# Name:    Eric Gronda
# Date:    11/27/17
# Section: 06
# E-mail:  gt32930@umbc.edu
# Description:
#    Takes data from dogData.txt and moves it to listDogs.txt

# CONSTANTS

NAME     = 0
BREED    = 1
GENDER   = 2
AGE      = 3
DURATION = 4

def main():
    
    # open program, get minimum stay
    print("Dogs are brought to adoption events based on time at the shelter.")
    stay = int( input("Please enter the minimum stay time for the dogs: ") )

    # open files
    ifp = open("dogData.txt" , "r")
    ofp = open("listDogs.txt" , "w")

    # create a list of strings
    dogList = ifp.readlines()

    for i in range( len(dogList) ):
        # separate each list by value
        dogList[i] = dogList[i].strip().split(",")
 
        # if the stay is longer than the minimum
        if int( dogList[i][DURATION] ) >= stay:
            
            # convert to string
            string =  str(dogList[i][NAME])     + ","
            string += str(dogList[i][BREED])    + ","
            string += str(dogList[i][GENDER])   + ","
            string += str(dogList[i][AGE])      + ","
            string += str(dogList[i][DURATION]) + "\n"
            
            # write string to file
            ofp.write( string )

    # close files
    ifp.close()
    ofp.close()

    #leave space
    print()

main()
