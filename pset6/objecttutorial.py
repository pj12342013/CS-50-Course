
class Student():

    def __init__(self, name, iden):
        self.name = name
        self.iden = iden
    def changeID(self, iden):
        self.iden = iden
    def print(self):
        print("{} - {}".format(self.name, self.iden))

jane = Student("Jane", 10)        
jane.print()
jane.changeID(11)
jane.print()

