/**
 * https://www.hackerearth.com/problem/algorithm/maximum-profit-5-c3c2ce7c/description/
 **/
package main

import (
	"sort"
)

func maximumProfit() {
	var n, t, ans, k, x int64
	scanf("%d", &t)
	for t > 0 {
		scanf("\n%d %d\n", &n, &k)
		coinMap := make(map[int64]bool)
		for i := int64(0); i < n; i++ {
			scanf("%d", &x)
			coinMap[x] = true
		}

		coins := make([]int64, len(coinMap))
		for coin := range coinMap {
			coins = append(coins, coin)
		}
		sort.Slice(coins, func(i, j int) bool {
			return coins[j] < coins[i]
		})

		ans = 0
		for i := 0; i < len(coins) && i < int(k); i++ {
			ans += coins[i]
		}
		printf("%d\n", ans)
		t--
	}
}
