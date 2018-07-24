def get_all_substrings(input_string):
    length = len(input_string)
    hc = [input_string[i:j + 1] for i in range(length) for j in range(i, length)]
    return [''.join(sorted(list(x))) for x in hc]


def get_hash(string):
    hc = {}
    for i in range(len(string)):
        if string[i] not in hc:
            hc[string[i]] = 0
        hc[string[i]] += 1
    return hc


q = int(input().strip())
while q > 0:
    ans = 0
    counts = {}
    string = input()
    all_subs = get_all_substrings(string)
    for substring in all_subs:
        if substring not in counts:
            counts[substring] = 0
        counts[substring] += 1
    for substring in counts:
        c = counts[substring]
        ans += ((c * (c - 1)) // 2)
    print(ans)
    q -= 1
