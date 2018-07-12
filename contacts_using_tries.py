#!/bin/python3
class node:
    def __init__(self, value):
        self.value = value
        self.count = 0
        self.childs = {}


class tree:
    def __init__(self):
        self.root = node("start")

    def add(self, name):
        self.add_string(name, self.root)

    def add_string(self, name, root):
        if len(name) == 0:
            root.count += 1
            return

        root.count += 1
        char = name[0]

        if char not in root.childs:
            root.childs[char] = node(char)

        self.add_string(name[1:], root.childs[char])

    def find(self, name, root):
        if len(name) == 0:
            return root.count

        char = name[0]
        if char not in root.childs:
            return 0

        return self.find(name[1:], root.childs[char])

    def partial(self, name):
        return self.find(name, self.root)


names = [
    "harish",
    "harry",
    "harris",
    "himanshu",
    "harsh",
    "harshit",
    "hari",
    "shivalika",
    "shadab",
    "shermeen",
    "shezad",
    "adhyan",
    "aditi",
    "aditya"
]

t = tree()
for name in names:
    t.add(name)


if __name__ == '__main__':
    n = int(input())
    t = tree()
    for n_itr in range(n):
        opContact = input().split()

        op = opContact[0]

        contact = opContact[1]
        if op == "add":
            t.add(contact)
        else:
            print(t.partial(contact))
