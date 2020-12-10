from cs50 import get_string


ccn = get_string("Credit Card Number: ")

copy = ccn[::-1]

check_sum = (sum([(int(x) * 2)// 10 + (int(x) * 2 % 10) for x in copy[1::2]]) +  sum([int(x) for x in copy[0::2]]))

if len(ccn) == 15 and ccn[0:2] in ["34", "37"]:
    print("AMEX")
elif len(ccn) == 16 and 51 <=int(ccn[0:2]) <= 55:
    print("MASTERCARD")
elif len(ccn) in [13, 16] and int(ccn[0]) == 4:
    print("VISA")
elif check_sum % 10 != 0:
    print("INVALID")
elif len(ccn) not in [15,16,13]:
    print("INVALID")





#American Express uses 15-digit numbers
    #starts with 34 or 37
#MasterCard uses 16-digit numbers
    #51-55 and upwards
#Visa uses 13- and 16-digit number
    #starts with 4


























