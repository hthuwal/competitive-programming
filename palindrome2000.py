string = ""

memo = [[-1] * 5002 for i in range(5002)]


def recursive(i, j):
    if i > j:
        return 10000000
    if i == j:
        return 0

    if memo[i][j] == -1:
        if i == j - 1:
            memo[i][j] = 0 if string[i] == string[j] else 1
        elif string[i] == string[j]:
            memo[i][j] = recursive(i + 1, j - 1)
        else:
            memo[i][j] = min(recursive(i + 1, j), recursive(i, j - 1)) + 1
    return memo[i][j]


n = input()
string = input().strip()


print(recursive(0, len(string) - 1))
