class Ice_cream:
    def __init__(self, id, cost):
        self.id = id
        self.cost = cost


def whatFlavors(ice_cream, amount):
    ice_cream.sort(key=lambda x: x.cost)
    i, j = 0, len(ice_cream) - 1

    while(i < j):
        cost = ice_cream[i].cost + ice_cream[j].cost
        if(cost == amount):
            return (ice_cream[i].id, ice_cream[j].id)

        if(cost < amount):
            i += 1
        else:
            j -= 1

    return (-1, -1)


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        money = int(input())

        n = int(input())

        cost = list(map(int, input().rstrip().split()))
        ice_cream = [Ice_cream(i + 1, cost[i]) for i in range(len(cost))]
        a, b = whatFlavors(ice_cream, money)
        if a < b:
            print(a, b)
        else:
            print(b, a)
