# Final Review Pact 16
# calculate fibonacci numbers use a dictionary to store them

#######################################################################
# fib()  generates a fibonacci number
# Input: pos;     an int, position of the fibonacci number
#        fibDict; dictionary to store old fibonaci numbers
def fib(pos, fibDict):
    # BASE CASE
    # invalid case
    if pos <= 0:
        return "That's not valid"

    # 1st position
    elif pos == 1:
        return 0

    # 2nd position
    elif pos == 2:
        return 1

    #######################################
    # RECURSIVE CASE
    # 3rd to nth position
    else:
        fibDict[pos - 1] = fib(pos - 1 , fibDict)
        fibDict[pos - 2] = fib(pos - 2 , fibDict)

        return fibDict[pos - 1] + fibDict[pos - 2]

def main():
    # get input
    userNum = int(input("Please enter you fibonacci number: "))

    # generate fibonacci number
    fibDict = {}
    fibNum = fib(userNum , fibDict)
    
    # print results
    print("Your" , userNum , "th fibonacci number is" , fibNum)

main()
