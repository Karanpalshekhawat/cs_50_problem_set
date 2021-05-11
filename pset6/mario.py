from cs50 import get_int

def main():
    while True:
        height = get_int("What is the Height of pyramid?   ")
        if height >= 1 and height <= 8:
            break
    create_pyramids(height)


def create_pyramids(h):
    dm = h;
    for i in range(1, h + 1):
        for j in range(1, h + 1):
            if (j>=dm):
                print("#", end="")
            else:
                print(" ", end="")

        print(" ", end="")
        print(" ", end="")
        k=h
        while k>=dm:
            print("#", end ="")
            k = k - 1
        print()
        dm = dm -1








if __name__=='__main__':
    main()