def isvowel(a):
    return a in ['a', 'e', 'i', 'o', 'u']


def isvalid(a):
    return isvowel(a[0]) and isvowel(a[-1])


def number_of_strings(stringArr, queries):
    n = len(stringArr)
    dp = [0] * n

    for i in range(n):
        dp[i] = 1 if isvalid(stringArr[i]) else 0
        if i != 0:
            dp[i] += dp[i - 1]

    ans = []
    for each in queries:
        a, b = each.strip().split('-')
        a, b = int(a) - 1, int(b) - 1
        if(a == 0):
            ans.append(dp[b])
        else:
            ans.append(dp[b] - dp[a - 1])

    return ans


if __name__ == '__main__':

    S = ['aab', 'a', 'bcd', 'awe', 'bbbbbu']
    Q = ['1-1', '1-4', '1-3', '2-5', '1-5']

    print(S)
    print(Q)
    print(number_of_strings(S, Q))

    print()

    S = ['yy', 'u', 'oe']
    Q = ['1-3', '2-3', '3-3']
    print(S)
    print(Q)
    print(number_of_strings(S, Q))

    print()

    S = ['aba', 'bcb', 'ece', 'aa', 'e']
    Q = ['1-5', '2-5', '2-2']
    print(S)
    print(Q)
    print(number_of_strings(S, Q))
