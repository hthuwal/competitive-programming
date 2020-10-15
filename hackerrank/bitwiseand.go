package main

import "fmt"

func solve1(n, k int32) int32 {
	a := int32(1)
	for a < n {
		a = 2 * a
	}
	a = a / 2
	a = a - 2
	if a >= k {
		return k - 1
	}
	return a
}

func solve2(n, k int32) int32 {
	ans := k & (k - 1)
	k--
	fmt.Println(ans, k)
	for k > ans {
		if x := k & (k - 1); x > ans {
			ans = x
		}
		k--
	}
	return ans
}

func main() {
	var t, n, k int32
	fmt.Scanf("%d", &t)
	for t > 0 {
		fmt.Scanf("%d %d", &n, &k)
		fmt.Println(k - 1)
		// if a, b := solve1(n, k), solve2(n, k); a < b {
		// 	fmt.Println(a, b)
		// } else {
		// 	fmt.Println(a, b)
		// }
		t--
	}
}
