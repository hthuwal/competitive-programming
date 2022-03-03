n, k = input().strip().split()
n, k = int(n), int(k)
costs = list(map(int, input().strip().split()))
costs.sort()

cost = 0
count = 1
for i in range(len(costs), -1, -k):
    l = i - k if (i - k) >= 0 else 0
    cost += sum(costs[l:i]) * count
    count += 1


print(cost)
