# Final Review Packet 11
# Get a list of integers from the user, then print forwards and backwards

QUIT = "q"

def main():
    numList = []
    msg = "Please enter a num ('q' to quit): "
    userNum = input(msg)

    # get numbers from user until quit
    while userNum != QUIT:
        if userNum != QUIT:
            numList.append( int(userNum) )
            userNum = input(msg)

    # print list forwards
    print("Your list is:       " , numList)

    # print list backwards
    backwards = []
    for i in range( len(numList) - 1 , -1 , -1 ):
        backwards.append(numList[i])

    print("Your backwards list:" , backwards)

main()
