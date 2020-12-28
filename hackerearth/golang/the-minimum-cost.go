/**
 * https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/min-cost-2-fe2d3308/
 **/
package main

import "fmt"

func solveTestCaseTheMimimumCost() {
	var n, c01, c10, costA, costB int64
	fmt.Scanf("%d %d %d", &n, &c01, &c10)

	bits := make([]int, n)
	for i := int64(0); i < n; i++ {
		fmt.Scanf("%d", &bits[i])
	}

	a, b := 0, 1
	costA = 0
	costB = 0
	for _, bit := range bits {
		if bit != a {
			costA += int64(bit^1)*c01 + int64(bit^0)*c10
		}

		if bit != b {
			costB += int64(bit^1)*c01 + int64(bit^0)*c10
		}
		a = a ^ 1
		b = b ^ 1
	}

	ans := costB
	if costA < costB {
		ans = costA
	}
	fmt.Println(ans)
}

func theMinimumCost() {
	var t int
	fmt.Scanf("%d", &t)

	for t > 0 {
		solveTestCaseTheMimimumCost()
		t--
	}
}
