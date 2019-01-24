def main():
    #A
    myList = [2 , 3 , 5 , 7]
    #B
    print(len(myList))
    #C
    index = 0
    while index < len(myList):
        print(myList[index])
        index += 1
    #D
    index = len(myList) - 1
    while index >= 0:
        print(myList[index])
        index -= 1

main()
