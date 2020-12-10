from csv import DictReader
from sys import argv, exit

#minimum 3 elements for command line argument
if len(argv) != 3:
    print("Usage python dna_copy.py databasefile sequencefile")
    exit(1)

#open dna_file
dna_file = open(argv[1], 'r')

#making strands[AGAT, ATTA] list and persons dictionary eg. Alice [1,2,3]
strands = []
persons = {}

#naming each row ind = 1; equals row Alice [2,8,3]. if ind =0 take str sequences else assign to current row. Stripping and splitting each row element
for ind, row in enumerate(dna_file):
     #taking the elements AGATA as list "strands[]"
    if ind == 0:
        strands = [strand for strand in row.strip().split(',')][1:]
    #populate persons dict with with current row 0th index and for loop for x in curr_row strating for 1st using int for loop
     #assigning names and sequence numbers into dictionary
    else:
        curr_row = row.strip().split(',')
        persons[curr_row[0]] = [int(x)for x in curr_row[1:]]

#opening sequences file with argv[2]
sequence_file = open(argv[2], 'r').read()

#declaring list of final_strands
final_strands = []


        #comparing current window with each strand from strand[]
        #making for loop iterating through each strand from strands[] assigning i counter, max_strand and curr_max. max strand to be -1
        #find a match for
for strand in strands:
    i = 0
    max_strand = -1
    curr_max = 0
    while i < len(sequence_file):
        #declare curr_window equal to sequence file iterating from i to the len of strand
        curr_window = sequence_file[i:i+len(strand)]
        #if current_windows finds a match increment that strand by 1
        if curr_window == strand:
            curr_max += 1
            #the max strand is the highest strand, global max strand. local curr_max
            max_strand = max(max_strand, curr_max)
            #i maintains the window and keeps the window moving. Increment it by len(strand)
            i += len(strand)
        #if curr_window does not == strand then curr_max = 0 and increment i by 1
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






















