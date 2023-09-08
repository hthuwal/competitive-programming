/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/number-of-provinces             */
/* -------------------------------------------------------------------------- */
package main

func FindCircleNum(isConnected [][]int) int {
	numComponents := 0

	n := len(isConnected)
	visited := make([]bool, n)

	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}

		numComponents += 1
		// Do a DFS for this component, visit everyone connected to it
		stack := []int{}
		stack = append(stack, i)

		for len(stack) > 0 {
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			visited[top] = true
			for nbr := 0; nbr < n; nbr++ {
				if (nbr != top) && !visited[nbr] && isConnected[top][nbr] == 1 {
					stack = append(stack, nbr)
				}
			}
		}
	}
	return numComponents
}
