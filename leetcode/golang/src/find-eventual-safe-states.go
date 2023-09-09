/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/find-eventual-safe-states          */
/* -------------------------------------------------------------------------- */

package main

func dfs(node int, visited []bool, states []int, graph [][]int) {
	if visited[node] {
		if states[node] == 0 {
			states[node] = -1
		}
		return
	}

	visited[node] = true
	for _, nbr := range graph[node] {
		dfs(nbr, visited, states, graph)
	}

	for _, nbr := range graph[node] {
		if states[nbr] == -1 {
			states[node] = -1
			return
		}
	}

	states[node] = 1
}

func EventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	visited := make([]bool, n)
	states := make([]int, n)

	for i := 0; i < n; i++ {
		if !visited[i] {
			dfs(i, visited, states, graph)
		}
	}

	ans := []int{}
	for i := 0; i < n; i++ {
		if states[i] == 1 {
			ans = append(ans, i)
		}
	}
	return ans
}
