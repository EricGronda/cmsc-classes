# Make a triangle using recursion

def tri(height):
    # BASE CASE
    # if on last row
    if height == 1:
        print("X")
        return 0    

    ################################
    # RECURSIVE CASE
    # if more rows to make
    if height > 1:
        # next level
        tri(height - 1)

        # create row
        for i in range(height - 1):
            print("X" , end="")
        print("X")
        
def main():
    
    # get input
    size = int( input("Height: "))

    # make triangle
    tri(size)

main()
