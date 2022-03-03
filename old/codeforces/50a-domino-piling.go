package golang

import "fmt"

func main() {
	var x, y, ans int
	fmt.Scanf("%d %d", &x, &y)
	if x&1 == 0 {
		x := x / 2
		ans = x * y
	} else if y&1 == 0 {
		y := y / 2
		ans = x * y
	} else {
		ans = ((x - 1) * (y - 1)) / 2
		ans = ans + (x-1)/2 + (y-1)/2
	}
	fmt.Println(ans)
}
