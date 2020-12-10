from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

cents = round(change * 100)

total =0;

for coin in [25, 10, 5, 1]:
    total += cents//coin
    cents %= coin
submit50 cs50/problems/2020/x/sentimental/credit
print(f"Total coins: {total}")




