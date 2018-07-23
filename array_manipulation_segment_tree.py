import math


def update(lazy, tree, tree_index, arr_start, arr_end, ul, ur, value):
    left = 2 * tree_index + 1
    right = 2 * tree_index + 2

    if lazy[tree_index] != 0:
        tree[tree_index] += lazy[tree_index]

        if arr_start != arr_end:
            lazy[left] += lazy[tree_index]
            lazy[right] += lazy[tree_index]

        lazy[tree_index] = 0

    if arr_start > ur or arr_end < ul:
        # out of range
        return

    if (ul <= arr_start and ur >= arr_end):
        tree[tree_index] += value

        if arr_start != arr_end:
            lazy[left] += value
            lazy[right] += value

        return

    mid = (arr_start + arr_end) >> 1
    update(lazy, tree, left, arr_start, mid, ul, ur, value)
    update(lazy, tree, right, mid + 1, arr_end, ul, ur, value)
    tree[tree_index] = max(tree[left], tree[right])


def main():
    n, m = list(map(int, input().strip().split()))
    size = 2**(math.ceil(math.log2(n)) + 1)
    tree = [0] * (size)
    lazy = [0] * (size)
    # create(tree, 0, 0, n - 1)
    for i in range(m):
        l, h, v = list(map(int, input().strip().split()))
        update(lazy, tree, 0, 0, n - 1, l - 1, h - 1, v)
    print(tree[0])


if __name__ == '__main__':
    main()
