# How to find the maximum in a list

def main():

    list1 = [1 , 7 , 100 , 3 , -4]
    maxVal = list1[0]
    index = 0
    while index < len(list1):
        if(maxVal < list1[index]):
            maxVal = list1[index]
        index += 1

    print("The max value in this list is" , maxVal)

main()
