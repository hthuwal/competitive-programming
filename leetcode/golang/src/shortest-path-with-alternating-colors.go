/* -------------------------------------------------------------------------- */
/*     https://leetcode.com/problems/shortest-path-with-alternating-colors    */
/* -------------------------------------------------------------------------- */

package main

import "math"

type Color int

const (
	Blue Color = iota
	Red
)

type Pair struct {
	node    int
	cameVia Color
}

func getGraphs(n int, redEdges [][]int, blueEdges [][]int) ([][]int, [][]int) {
	redGraph := make([][]int, n)
	for i := range redGraph {
		redGraph[i] = []int{}
	}

	blueGraph := make([][]int, n)
	for i := range blueGraph {
		blueGraph[i] = []int{}
	}

	for _, edge := range redEdges {
		redGraph[edge[0]] = append(redGraph[edge[0]], edge[1])
	}

	for _, edge := range blueEdges {
		blueGraph[edge[0]] = append(blueGraph[edge[0]], edge[1])
	}

	return redGraph, blueGraph
}

func bfs(redGraph, blueGraph [][]int, distanceViaRed, distanceViaBlue []int) {
	queue := []Pair{}
	for i := range distanceViaBlue {
		distanceViaBlue[i] = math.MaxInt32
		distanceViaRed[i] = math.MaxInt32
	}
	queue = append(queue, Pair{0, Blue})
	queue = append(queue, Pair{0, Red})

	distanceViaBlue[0] = 0
	distanceViaRed[0] = 0

	for len(queue) > 0 {
		front := queue[0]
		queue = queue[1:]

		if front.cameVia == Red {
			nbr_new_dist := distanceViaRed[front.node] + 1

			for _, nbr := range blueGraph[front.node] {
				if nbr_new_dist < distanceViaBlue[nbr] {
					queue = append(queue, Pair{nbr, Blue})
					distanceViaBlue[nbr] = nbr_new_dist
				}
			}
		}

		if front.cameVia == Blue {
			nbr_new_dist := distanceViaBlue[front.node] + 1
			for _, nbr := range redGraph[front.node] {
				if nbr_new_dist < distanceViaRed[nbr] {
					queue = append(queue, Pair{nbr, Red})
					distanceViaRed[nbr] = nbr_new_dist
				}
			}
		}
	}

}

func ShortestAlternatingPaths(n int, redEdges [][]int, blueEdges [][]int) []int {

	redGraph, blueGraph := getGraphs(n, redEdges, blueEdges)

	distanceViaBlue := make([]int, n)
	distanceViaRed := make([]int, n)
	bfs(redGraph, blueGraph, distanceViaBlue, distanceViaRed)

	distance := []int{}
	for i := range distanceViaBlue {
		dist := distanceViaBlue[i]
		if distanceViaRed[i] < dist {
			dist = distanceViaRed[i]
		}

		if dist == math.MaxInt32 {
			dist = -1
		}
		distance = append(distance, dist)
	}

	return distance
}
