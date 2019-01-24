# File:    hw6_part3.py
# Author:  Eric Gronda
# Date:    11/15/2017
# Section: 06
# E-mail: gt32930@umbc.edu
# Description:
#    Counts the number of ears and horns in a line of horses and unicorns
#    Note: the horses and unicorns alternate (with the unicorn at the front)

############################################################################
# count() counts the number of ears and horns in line of horses and unicorns
# Input:  line; length of the line to count through
# Output: earsAndHorns; number of ears and horns in the line
def count(line):
    
    # BASE CASE
    if line == 0:
        return 0

    # RECURSIVE CASE

    # count unicorns at odd positions
    elif line % 2 != 0:
        return count(line - 1) + 3
    # count horses at even positions
    elif line % 2 == 0:
        return count(line - 1) + 2

def main():

    # get length of line
    line = int(input("How long is the line of equines? "))

    # calculate number of ears and horns
    earsAndHorns = count(line)

    # display results
    results = "In a line of " + str(line) + " equines, there are "
    results += str(earsAndHorns) + " ears and horns."
    print(results)

main()
