/* -------------------------------------------------------------------------- */
/*      https://leetcode.com/problems/nearest-exit-from-entrance-in-maze      */
/* -------------------------------------------------------------------------- */
package main

func NearestExit(maze [][]byte, entrance []int) int {
	n, m := len(maze), len(maze[0])

	q := make([][]int, 0, len(maze)*len(maze))
	q = append(q, []int{entrance[0], entrance[1], 0})

	isValidIndex := func(i, j, n, m int) bool {
		return i >= 0 && i < n && j >= 0 && j < m && maze[i][j] != '+'
	}

	isExit := func(i, j, n, m int) bool {
		return i == n-1 || i == 0 || j == 0 || j == m-1
	}

	isStart := func(i, j int) bool {
		return i == entrance[0] && j == entrance[1]
	}

	steps := []int{0, -1, 0, 1, 0}

	// Mark it visited by putting up a wall
	maze[entrance[0]][entrance[1]] = '+'
	for len(q) > 0 {
		x, y, dist := q[0][0], q[0][1], q[0][2]
		q = q[1:]

		for i := 0; i < len(steps)-1; i++ {
			nbrx, nbry := x+steps[i], y+steps[i+1]
			if isValidIndex(nbrx, nbry, n, m) {
				maze[nbrx][nbry] = '+'
				q = append(q, []int{nbrx, nbry, dist + 1})

				if !isStart(nbrx, nbry) && isExit(nbrx, nbry, n, m) {
					return dist + 1
				}
			}
		}
	}

	return -1
}
