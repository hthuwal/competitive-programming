// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

package main

func MakeConnected(n int, connections [][]int) int {
	if len(connections) < n-1 {
		return -1
	}

	adj_list := make(map[int][]int)
	for _, edge := range connections {
		if val, ok := adj_list[edge[0]]; !ok {
			adj_list[edge[0]] = []int{edge[1]}
		} else {
			adj_list[edge[0]] = append(val, edge[1])
		}

		if val, ok := adj_list[edge[1]]; !ok {
			adj_list[edge[1]] = []int{edge[0]}
		} else {
			adj_list[edge[1]] = append(val, edge[0])
		}
	}

	visited := make([]bool, n)
	num_components := 0
	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}

		num_components += 1

		// Use channels as queue
		q := make(chan int, n)
		q <- i
		visited[i] = true
		for len(q) != 0 {
			front := <-q
			if nbrs, ok := adj_list[front]; ok {
				for _, nbr := range nbrs {
					if !visited[nbr] {
						q <- nbr
						visited[nbr] = true
					}
				}
			}
		}
	}

	return num_components - 1
}
