/**
 * https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/multiple-occurence-97c00160/
 **/
package main

import "fmt"

type tupleMultipleOccurrences struct {
	low  int
	high int
}

func multipleOccurrences() {
	var n, t, x int
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanf("%d", &n)
		freq := make(map[int]tupleMultipleOccurrences)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &x)
			if val, ok := freq[x]; ok {
				val.high = i
				freq[x] = val
			} else {
				freq[x] = tupleMultipleOccurrences{i, i}
			}
		}

		ans := 0
		for _, val := range freq {
			ans += val.high - val.low
		}
		fmt.Println(ans)
	}
}
