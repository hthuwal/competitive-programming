package golang

import "fmt"

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if x&1 == 1 || x == 2 {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
	}
}
