/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/all-paths-from-source-to-target       */
/* -------------------------------------------------------------------------- */
package main

func AllPathsSourceTarget(graph [][]int) [][]int {
	target := len(graph) - 1

	// Without Pre allocation
	// 7-12ms, Beats 60-85%
	// paths := [][]int{}
	// stack_of_paths := [][]int{}

	// With Pre allocation: 3ms, Beats 99.01%
	paths := make([][]int, 0, len(graph)*len(graph))
	stack_of_paths := make([][]int, 0, len(graph)*len(graph))
	stack_of_paths = append(stack_of_paths, []int{0})

	for len(stack_of_paths) > 0 {
		top_path := stack_of_paths[len(stack_of_paths)-1]
		stack_of_paths = stack_of_paths[:len(stack_of_paths)-1]

		last_node_in_path := top_path[len(top_path)-1]
		for _, nbr := range graph[last_node_in_path] {
			updated_path := make([]int, len(top_path))
			copy(updated_path, top_path)
			updated_path = append(updated_path, nbr)
			if nbr == target {
				paths = append(paths, updated_path)
			} else {
				stack_of_paths = append(stack_of_paths, updated_path)
			}
		}
	}

	return paths
}
