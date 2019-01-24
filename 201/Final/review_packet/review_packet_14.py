# Final Review Packet 14
# Create a 2D list where contents count up and inner list size shrinks

##########################################################################
# makeList() makes a 2D list that counts up contents and shrinks col size
# Input:     rows;    an int, number of rows to be created
#                     (also number of columns in row)
#            list2D;  list to append to
#            currNum; current value of number in column
# Output:    list2D; fully created 2D list
def makeList(rows , list2D , currNum):
    # BASE CASE
    # if row size is zero
    if rows < 1:
        return list2D
        
    ##################################
    # RECURSIVE CASE
    # if there is a row to append
    else:
        # create a list to append
        newRow = []
        for i in range(rows):
            currNum += 1
            newRow.append(currNum)

        # append to 2D list
        list2D.append(newRow)

        # repeat with rows - 1
        return makeList(rows - 1 , list2D , currNum)

def main():

    # get input
    userNum = int(input("Please enter a number: "))
    
    # create 2D list
    list2D = []
    list2D = makeList(userNum , list2D , 0)

    # print list
    print("Your 2D list is:" , list2D)

main()
