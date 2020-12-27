package main

import "fmt"

type tuple struct {
	low  int
	high int
}

func main() {
	var n, t, x int
	fmt.Scanf("%d", &t)
	for ; t > 0; t-- {
		fmt.Scanf("%d", &n)
		freq := make(map[int]tuple)
		for i := 0; i < n; i++ {
			fmt.Scanf("%d", &x)
			if val, ok := freq[x]; ok {
				val.high = i
				freq[x] = val
			} else {
				freq[x] = tuple{i, i}
			}
		}

		ans := 0
		for _, val := range freq {
			ans += val.high - val.low
		}
		fmt.Println(ans)
	}
}
