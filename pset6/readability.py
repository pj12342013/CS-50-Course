from cs50 import get_string

n = get_string("Text: ")

letters = words = sentences = 0

for char in n:
    if char.isalpha():
        letters += 1
    if char.isspace():
        words += 1
    if char in ["?", "!","."]:
        sentences += 1

words += 1

L = (letters * 100.00) / words
S = (sentences * 100.00) / words

index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index <= 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")




#Coleman Liu Index = 0.0588 * L - 0.296 * S - 15.8
# Letters for 100 words and Sentences for 100 words