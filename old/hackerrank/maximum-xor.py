"""
Its necessary that the trie is created from the highest
bit position to lowest bit. Then only the query method
results in maximum xor.
"""


def add(trie, n):
    root = trie
    # find binary representation
    b = bin(n)[2:]
    b = list(map(int, list(b)))

    # prepend 0's to make it 32bit
    b = [0] * (32 - len(b)) + b

    # if edge labelled bit does not exist at root
    # create it. New edge points to a {} (node)
    for bit in b:
        if bit not in root:
            root[bit] = {}
        root = root[bit]


def max_xor(trie, n):
    temp = trie
    ans = []

    # find binary representation
    b = bin(n)[2:]
    b = list(map(int, list(b)))

    # prepend 0's to make it 32bit
    b = [0] * (32 - len(b)) + b

    for bit in b:
        tbit = 1 - int(bit)

        # if the opposite bit exist choose it
        if tbit in temp:
            temp = temp[tbit]
            ans.append(str(tbit))

        # otherwise choose whats available
        elif bit in temp:
            temp = temp[bit]
            ans.append(str(bit))

    ans = int("".join(ans), 2)
    return ans


n = int(input().strip())
arr = list(map(int, input().strip().split()))
trie = {}
for number in arr:
    add(trie, number)

m = int(input().strip())
while m > 0:
    q = int(input().strip())
    print(q ^ max_xor(trie, q))
    m -= 1
