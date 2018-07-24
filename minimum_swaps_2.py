# https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/


def solve(arr):
    cycles = []  # each swap sequence will form a cycle

    sorted_arr = sorted(arr)
    correct_pos = {sorted_arr[i]: i for i in range(len(sorted_arr))}  # what there correct positions should have been
    visited = {ele: False for ele in arr}  # number is visited or not (considered in a cycle or not)

    for i in range(len(arr)):
        ele = arr[i]
        cycle_size = 0
        if not visited[ele] and correct_pos[ele] != i:
            while(not visited[ele]):
                visited[ele] = True
                cycle_size += 1
                ele = arr[correct_pos[ele]]
            cycles.append(cycle_size)

    return sum(cycles) - len(cycles)


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().strip().split()))
    print(solve(arr))
