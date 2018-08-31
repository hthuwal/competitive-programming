def merge(a, l, m, h):
    i = l
    j = m + 1
    temp = [0] * (h - l + 1)
    k = 0
    inversions = 0
    while i <= m and j <= h:
        if (a[i] <= a[j]):
            temp[k] = a[i]
            k += 1
            i += 1
        else:
            inversions += (m - i + 1)
            temp[k] = a[j]
            k += 1
            j += 1

    while i <= m:
        temp[k] = a[i]
        k += 1
        i += 1

    while j <= h:
        temp[k] = a[j]
        k += 1
        j += 1

    for i in range(len(temp)):
        a[l + i] = temp[i]

    return inversions


def mergesort(a, l, h):
    if l < h:
        m = (l + h) // 2
        iil = mergesort(a, l, m)
        iir = mergesort(a, m + 1, h)
        iblar = merge(a, l, m, h)
        return iil + iir + iblar
    return 0


def countInversions(arr):
    return mergesort(arr, 0, len(arr) - 1)
