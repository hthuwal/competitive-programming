/**
 * https://www.spoj.com/problems/INVCNT/
 **/
package main

type mergeSorterInversionCount struct {
	invCount int64
}

func (m *mergeSorterInversionCount) mergeInversionCount(list []int, s, mid, e int) {
	i, j, k := s, mid+1, 0
	mergedList := make([]int, e-s+1)

	for i <= mid && j <= e {
		if list[i] <= list[j] {
			mergedList[k] = list[i]
			k++
			i++
		} else {
			m.invCount += (int64)(mid - i + 1)
			mergedList[k] = list[j]
			k++
			j++
		}
	}

	for i <= mid {
		mergedList[k] = list[i]
		k++
		i++
	}

	for j <= e {
		mergedList[k] = list[j]
		k++
		j++
	}

	for k = 0; k < len(mergedList); k++ {
		list[s+k] = mergedList[k]
	}
}

func (m *mergeSorterInversionCount) mergeSortInversionCount(list []int, s, e int) {
	if s < e {
		mid := s + (e-s)/2
		m.mergeSortInversionCount(list, s, mid)
		m.mergeSortInversionCount(list, mid+1, e)
		m.mergeInversionCount(list, s, mid, e)
	}
}

func inversionCount() {
	var t, n int
	scanf("%d\n", &t)
	m := mergeSorterInversionCount{}
	for t > 0 {
		scanf("\n")
		scanf("%d\n", &n)
		list := make([]int, n)
		for i := 0; i < n; i++ {
			scanf("%d\n", &list[i])
		}
		m.invCount = 0
		m.mergeSortInversionCount(list, 0, n-1)
		printf("%d\n", m.invCount)
		t--
	}
}
