from cs50 import get_int

while True:
    h = get_int("Height: ")
    if 9 > h > 0 :
        break

for r in range(1, h + 1):
    print(" " * (h - r) + "#" * r + " " * 2 + "#" * r )






