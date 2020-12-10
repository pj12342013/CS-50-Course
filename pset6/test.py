num = [x for x in range(5)]

num.append(5)

num.insert(6,6)

num[len(num):] = [7]

#print(num)

dictionary = {'pizza': 1, 'pepporoni': 2, 'corn': 3, 'potato': 17}

dictionary['pizza'] = 5

dictionary['chicken'] = 14


for pizzas, number in dictionary.items():
    print("a "+ pizzas +" pizza costs " + str(number))

