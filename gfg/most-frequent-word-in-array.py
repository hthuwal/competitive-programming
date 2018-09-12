# https://practice.geeksforgeeks.org/problems/most-frequent-word-in-an-array-of-strings/0

from collections import Counter

t = int(input())
while t > 0:
    n = int(input())
    words = input().strip().split()
    words = list(Counter(words).items())
    words.sort(key=lambda x: x[1], reverse=True)
    max_freq = words[0][1]
    words = [each for each in words if each[1] == max_freq]
    words.sort(key=lambda x: x[0])
    print(words[0][0])
    t -= 1
