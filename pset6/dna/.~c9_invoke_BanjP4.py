from sys import argv, exit
from csv import DictReader

import sys
#minimum 3 elements for command line argument
if len(argv) != 3:
    print("python dna.py data.csv sequence.txt")
    exit(1)

#open dna_file
dna_file = open(argv[1], 'r')

#making strands[AGAT, ATTA] list and persons dictionary eg. Alice [1,2,3]
strands = []
persons = {}


#naming each row ind = 1; equals row Alice [2,8,3]
for ind, row in enumerate(dna_file):
    #taking the elements AGATA as list "strands[]"
    if ind == 0:
        strands = [strand for strand in row.strip().split(',')][1:]
    #assigning names and sequence numbers into dictionary
    else:
        curr_row = row.strip().split(',')
        persons[curr_row[0]] = [int(x) for x in curr_row[1:]]

#opening sequences file with argv[2]
sequence_file = open(argv[2], "r").read()


final_strands = []

for strand in strands:
    i = 0
    max_strand = -1
    curr_max = 0
    while i < len(sequence_file): #iterate through file
        #comparing current window with each strand from strand[]
        curr_window = sequence_file[i:i + len(strand)]
        #if current_windows finds a match increment that strand by 1
        if curr_window == strand:
            curr_max += 1
            #the max strand figures out the highest strand, global max strand. local curr_max
            max_strand = max(max_strand, curr_max)
            #i maintains the window and keeps the window moving
            i += len(strand)
        else:
            curr_max = 0
            i += 1
    #final strands keep track of the max number of strands for a sequence
    final_strands.append(max_strand)

#check if data in person{} matches final_strands. if so print names. Else print no match
for names, data in persons.items():
    if data == final_strands:
        print(names)
        exit(0)

print("No match")






#take rows 1 and search for them in argv2









#check row[1-8] in argv[1]
#compare with row in argv[2]









