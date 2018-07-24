def get_all_substrings(input_string):
    length = len(input_string)
    return [input_string[i:j + 1] for i in range(length) for j in range(i, length)]


def get_hash(string):
    hc = {}
    for i in range(len(string)):
        if string[i] not in hc:
            hc[string[i]] = 0
        hc[string[i]] += 1
    return hc


hashes = {}

q = int(input().strip())
while q > 0:
    ans = 0
    string = input()
    all_subs = get_all_substrings(string)
    for i in range(len(all_subs)):
        for j in range(i + 1, len(all_subs)):
            a = all_subs[i]
            b = all_subs[j]
            if a not in hashes:
                hashes[a] = get_hash(a)
            if b not in hashes:
                hashes[b] = get_hash(b)

            if (hashes[a] == hashes[b]):
                ans += 1
    print(ans)
    q -= 1
