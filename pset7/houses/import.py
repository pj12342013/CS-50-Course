
from sys import argv, exit
from cs50 import SQL
import csv


if len(argv) != 2:
    print("Usage python import.py filename.csv")
    exit(1)
#access to db files
db = SQL("sqlite:///students.db")

char_list = []
name = ()
house = []
year = []
#read argv 2 csv file
with open(argv[1], 'r') as char_file:
    reader = csv.DictReader(char_file)

    for row in reader:
        curr_name = row['name'].split()
        if len(curr_name) == 3:
            first, middle, last = curr_name
        else:
            first, last = curr_name
            middle = None
        house = row['house']
        birth = row['birth']

        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)", first, middle, last, house, birth)

















#db = SQL("sqlite:///students.db")







