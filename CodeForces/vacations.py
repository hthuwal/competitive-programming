"""
https://codeforces.com/problemset/problem/698/A
"""

num_of_days = int(input().strip())


events = list(map(int, input().strip().split()))

# dp_code[i] stores minimum number of days you have to take rest if you try to do code on ith holiday
# dp_gym[i] stores minimum number of days you have to take rest if you try to do gym on ith holiday

dp_code = [0] * (num_of_days + 1)
dp_gym = [0] * (num_of_days + 1)

# you can't rest if you have no holidays
dp_code[0] = 0
dp_gym[0] = 0

for i in range(1, num_of_days + 1):

    # if both gym and coding options are closed, you got to take leave today, take the best of before
    if events[i - 1] == 0:
        dp_code[i] = min(dp_code[i - 1], dp_gym[i - 1]) + 1
        dp_gym[i] = min(dp_code[i - 1], dp_gym[i - 1]) + 1

    # if I can do coding today but not gym
    elif events[i - 1] == 1:
        dp_code[i] = dp_gym[i - 1]  # I got to do gym yesterday
        dp_gym[i] = min(dp_code[i - 1], dp_gym[i - 1]) + 1  # I only wanna do gym but gym is closed so chutti

    # If I can do gym today but not code
    elif events[i - 1] == 2:
        dp_gym[i] = dp_code[i - 1]  # I got to do code yesterday
        dp_code[i] = min(dp_code[i - 1], dp_gym[i - 1]) + 1  # I only wanna do code but no contests so chutti

    # If I can do both
    else:
        dp_gym[i] = dp_code[i - 1]  # to do gym today, do code yesterday
        dp_code[i] = dp_gym[i - 1]  # to do code today, do gym yesterday

# print(dp_code)
# print(dp_gym)
print(min(dp_code[num_of_days], dp_gym[num_of_days]))
