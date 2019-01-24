# Final Review Packet 12
# Recursively determines if a number is prime

######################################################################
# prime() uses recursion to determine if a number is prime
# Input:  num;   an integer
# Output: prime; boolean value, True if num is prime and vice-versa
def prime(num , div):
    # BASE CASE
    # if all divisors checked, return True
    if div <= 1:
        return True

    # if the num can be divided by a number less than it
    elif (num / div) == (num // div):
        return False

    #########################################################
    # RECURSIVE CASE
    # check the next number
    else:
        return prime(num , div - 1)

def main():
    
    # get number
    userNum = int(input("Please enter a number: "))

    # check to see if prime number
    primeValue = prime(userNum , userNum - 1)

    if primeValue == True:
        print("The number" , userNum , "is a prime number.")
    else:
        print("The number" , userNum , "is not a prime number.")
 
main()
