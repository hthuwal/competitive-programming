from collections import Counter

t = int(input().strip())

while(t > 0):
    points = []
    for i in range(5):
        x = list(map(int, input().strip().split()))
        points.append(x)

    x_set, y_set = zip(*points)
    x_set, y_set = Counter(x_set), Counter(y_set)

    ans = True
    if len(x_set) == 3 and len(y_set) == 3:
        x, y = None, None
        for key in x_set:
            if x_set[key] == 3:
                x = key

        for key in y_set:
            if y_set[key] == 3:
                y = key

        if x is not None and y is not None:
            temp = [each for each in points if each[0] == x and each[1] == y]
            if len(temp) != 1:
                ans = False
            else:
                temp = [each[1] for each in points if each[0] == x]
                temp.sort()
                
                if temp[0] != temp[1] - 1 or temp[1] != temp[2] - 1:
                    ans = False
                else:
                    temp = [each[0] for each in points if each[1] == y]
                    temp.sort()
                    if temp[0] != temp[1] - 1 or temp[1] != temp[2] - 1:
                        ans = False
        else:
            ans = False
    else:
        ans = False

    if ans:
        print("Yes")
    else:
        print("No")
    t -= 1
