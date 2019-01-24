# Final Review Packet 15
# takes in an integer and determines if it is a power of two

######################################################################
# powerOfTwo() determines if a number is a power of two
# Input:       num;  an int
# Output:      True  (if num is power of two)
#              False (if num is not  power of two)
def powerOfTwo(num):
    # BASE CASE
    # if gone through all options
    if num == 1:
        return True

    # if the number is odd
    elif num % 2 == 1:
        return False

    ##########################################
    # RECURSIVE CASE
    # if number is even
    elif num % 2 == 0:
        return powerOfTwo(num // 2)
        

def main():
    # get input
    userNum = int(input("Please enter a number: "))
    
    # check if num is a power of two
    value = powerOfTwo(userNum)

    # if not a power of two
    if value == False:
        print("The number" , userNum , "is not a power of two.")
    # if a power of two
    else:
        print("The number" , userNum , "is a power of two.")

main()
