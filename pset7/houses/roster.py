from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    print("Usage python roster.py house")
    exit(1)

housename = argv[1].lower()

houses = ["ravenclaw", "hufflepuff", "slytherin", "gryffindor"]

if housename not in houses:
    print("use correct house name")

db = SQL("sqlite:///students.db")

data = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC;", argv[1])

for row in data:
    if row['middle'] != None:
        print(f"{str(row['first'])} {str(row['middle'])} {str(row['last'])}, born {str(row['birth'])}")

    else:
        print(f"{str(row['first'])} {str(row['last'])}, born {str(row['birth'])}")

















