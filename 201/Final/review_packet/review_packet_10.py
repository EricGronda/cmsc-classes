# Final Review Packet 10
# Get a list of integers from the user, then bubble sort the numbers
# in the list

QUIT = "q"

#######################################################################
# bubbleSort() bubble sorts a list of numbers
# Input:       numList; list of integers
# Output:      none     (prints to screen)
def bubbleSort(numList):
    swaps  = 0
    passes = 0

    # do a bunch of passes
    for j in range( len(numList) ):
        passes += 1

    # do a bunch of swaps
        for i in range( len(numList) ):
            # if the number is greater the one before it, swap
            if (i + 1) < len(numList) and numList[i] > numList[i + 1]:
                swaps += 1
                currNum = numList[i]
                nextNum = numList[i + 1]
                
                numList[i]     = nextNum
                numList[i + 1] = currNum
    
    print()
    print("\tNumber of swaps: " , swaps)
    print("\tNumber of passes:" , passes)
    print()
    print("Sorted List:" , numList)
    print()        


def main():
    numList = []
    msg = "Please enter a num ('q' to quit): "
    userNum = input(msg)

    # get numbers from user until quit
    while userNum != QUIT:
        if userNum != QUIT:
            numList.append( int(userNum) )
            userNum = input(msg)
    
    print("You're list is:" , numList)

    bubbleSort(numList)

main()
