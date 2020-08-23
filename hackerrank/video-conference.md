### Video Conference: Question in HourRank30

Bob is making a video conference software. Whenever a new person joins the conference, Bob displays the person's name in the interface.

However, displaying full name is tedious and takes much space. So he decided to display the shortest prefix which doesn't match with any prefix of any person who has joined earlier.

If the full name of a new person matches completely with the full name of any person who has joined earlier, he will display the full name and add a suffix which indicates how many times the same name has occurred in the list so far. 

**Sample Input**
```
3
alvin
alice
alvin
```

**Sample Output**
```
a
ali
alvin 2
```

Write a function that accepts a string array of names, and returns a string array denoting the strings that will be displayed after everyone has joined.

--- 

**Python code**
```python
def solve(names):
    trie = {} ## dict to represent trie data structure
    count = {} ## to store frequency of each name
    ans = [] ## list of strings to be returned

    for each in names:
        temp = trie ## temp variable that points to head of trie
        added = False ## the entry corresponding to this word hasn't been made yet
        
        ## add this name to the trie
        for i in range(len(each)):
            l = each[i]
            if l not in temp:
                ## the first new letter in the denotes the end of the prefix
                ## that will be used fr this name
                if not added: 
                    ans.append(each[0:i+1])
                    added = True
                temp[l] = {}
            temp = temp[l]
        
        ## store the frequency of this word
        if each not in count:
            count[each] = 0
        count[each] += 1
        
        ## if the prefix for this word wasn't added 
        ## => the world was already present in the trie.
        if not added:
            ## this would happen if this word appeared for the 
            ## first time but is a prefix to some other word
            if count[each] == 1:
                ans.append(each)
            ## this would happen if the word had occurred before
            else:
                ans.append(each+" "+str(count[each]))
    return ans
```