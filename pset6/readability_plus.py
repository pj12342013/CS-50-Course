from cs50 import get_string

n = get_string("input:")

letters = len(n) - n.count(" ") - n.count(".") - n.count("!") - n.count("?")

sentences = n.count(".") + n.count("!") + n.count("?")

words = n.count(" ") + 1

index = round(0.0588 * ((letters * 100)// words) - 0.296 * ((sentences * 100)// words)  - 15.8)

print(f"index = {index}")
print(f"words = {words}")
print(f"letters = {letters}")
print(f"sentences ={sentences}")



if index >= 16:
    print("Grade 16+")
elif index <= 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")




#Coleman Liu Index = 0.0588 * L - 0.296 * S - 15.8
# Letters for 100 words and Sentences for 100 words