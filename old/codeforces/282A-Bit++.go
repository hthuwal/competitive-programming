package main

import "fmt"

func main() {
	var x, n int
	var op string
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &op)
		if op == "++X" || op == "X++" {
			x++
		} else if op == "--X" || op == "X--" {
			x--
		}
	}
	fmt.Println(x)
}
