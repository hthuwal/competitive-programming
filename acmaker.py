def findoccurences(word, ch):
    return [i for i, c in enumerate(word) if c == ch]


memo = {}


def memoize(f):
    def helper(abr, phrase):
        x = abr+"".join(phrase)
        if x not in memo:           
            memo[x] = f(abr, phrase)
        return memo[x]
    return helper


@memoize
def recursive(abr, phrase):
    if abr == '' and phrase == []:
        return 1
    elif abr == '':
        return 0
    elif phrase == []:
        return 0

    cur_word = phrase[0]
    c = abr[0].lower()
    
    if c in cur_word:
        indices = findoccurences(cur_word, c)
        count = 0
        
        for i in indices:
            if(i != len(cur_word)-1):
                phrase[0] = cur_word[i+1:]
                count += recursive(abr[1:], phrase)

            count += recursive(abr[1:], phrase[1:])

        return count

    else:
        return 0


def solve(abr_and_phrases):
    
    for phrase in abr_and_phrases:
        memo.clear()
        no_of_ways = recursive(phrase[0], phrase[1:])
        if(no_of_ways == 0):
            print phrase[0], "is not a valid abbreviation"
        else:
            print phrase[0], "can be formed in", no_of_ways, "ways"

count = 0
while True:
    phrases = []
    insig = []

    # input
    n = int(raw_input().strip())
    if n == 0:
        break
    for _ in range(n):
        insig.append(raw_input().strip())
    while True:
        inp = raw_input().strip()
        if inp == "LAST CASE":
            break
        inp = [x for x in inp.split() if x not in insig]
        phrases.append(inp)
    # print phrases
    solve(phrases)