

def main():

    maxHt = int(input("Enter Height: "))
    curHt = 0
    out = input("Enter Outline: ")
    fil = input("Enter Fill: ")

    # iterate height
    while curHt < maxHt - 1:
        # start
        if curHt == 0:
            print(out)
        elif curHt == 1:
            print(out * 2)
        else:
            print(out , end="")

        # print middle
        if curHt > 1: # and curHt < maxHt - 1:
            count = 0
            while count < curHt - 1:
                print(fil , end="")
                count += 1

        # end line
        if curHt > 1: # and curHt < maxHt - 1:
            print(out)
        
            
        curHt += 1

    # finish triangle
    print(out * maxHt)
    
main()
