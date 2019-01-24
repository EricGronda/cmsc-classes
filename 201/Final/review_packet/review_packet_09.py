# Final Review Packet Number 9
# turn names into intitials

#############################################################################
# makeInitials() takes in a full name and returns the initials
# (for example: "Freeman A Hrabowski" becomes "F.A.H.")
# Input:         name;     a string
# Output:        initials; a string of initials
def makeInitials(name):
    
    # separate first/middle/last names
    nameList = name.split()

    initials = ""
    
    for i in range( len(nameList) ):
        currName = nameList[i]
        # take the first letter from each name
        firstLetter = currName[0]

        # format and add to the current initials
        tempInitial = firstLetter.upper()
        initials = initials + tempInitial + "."

    return initials

def main():
    myName = input("Please enter a name: ")
    myInitials = makeInitials(myName)
    print("The intitials for" , myName , " are:" , myInitials)

main()
