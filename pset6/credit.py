from cs50 import get_int

def main():
    ccnum = get_int("Enter Credit card number: ")
    digits = len(str(ccnum))

    if digits == 16 or digits == 13 or digits == 15:
        con = check_validity(ccnum, digits)
    else:
        con = False

    if con:
        if str(ccnum)[0] in ['4']:
            print("VISA")
        elif str(ccnum)[:2] in ['51', '52', '53', '54', '55']:
            print("MASTERCARD")
        elif str(ccnum)[:2] in ['34', '37']:
            print('AMEX')
        else:
            print("INVALID")
    else:
        print("INVALID")


def check_validity(num, dig):
    sum1=0
    sum2=0
    flag =0
    flag2=0
    count=1
    for i in range(dig - 1, -1, -1):
        flag = int(str(num)[i])
        if (count) % 2 == 0:
            flag2 = flag * 2
            if flag2 > 9:
                tmp = int(str(flag2)[0]) + int(str(flag2)[1])
                flag2 = tmp
            sum1 = sum1 + flag2
        else:
            sum2 = sum2 + flag
        count+=1
    final_num = sum1 + sum2
    if final_num % 10 ==0:
        return True
    else:
        return False



if __name__=='__main__':
    main()