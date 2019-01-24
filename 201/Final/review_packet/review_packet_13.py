# Final Review Packet 13
# use recursion to find the maximum number in a list

QUIT = "q"

#####################################################################
# maxx() recursively determines the maximum number in a list
# Input:  nums;   a list of integers
#         index;  current index in list of numbers
#         maxNum; current maximum number in list 
# Output: maxNum; maximum number in a list
def maxx(nums , index , maxNum):
    # BASE CASE
    # if number is last number in list
    if index >= len(nums) - 1:
        return maxNum

    #######################################
    # RECURSIVE CASE
    # if number greater than the next index
    elif maxNum > nums[index + 1]:
        return maxx(nums , index + 1 , maxNum)
    
    # if number less than or equal to the next index
    elif maxNum <= nums[index + 1]:
        newMax = nums[index + 1]
        return maxx(nums , index + 1 , newMax)

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

    if len(numList) > 0:
        maxNum = maxx(numList , 0 , numList[0])
        print("The maximum number is:" , maxNum)

    else:
        print("There is no max")


main()
