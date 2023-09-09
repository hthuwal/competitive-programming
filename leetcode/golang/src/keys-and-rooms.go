/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/keys-and-rooms                */
/* -------------------------------------------------------------------------- */

package main

import "fmt"

func CanVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)

	visited := make([]bool, n)
	stack := []int{0}

	for len(stack) > 0 {
		top := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		fmt.Println(top)
		visited[top] = true
		for _, nbr := range rooms[top] {
			if !visited[nbr] {
				stack = append(stack, nbr)
			}
		}
	}

	for _, v := range visited {
		if !v {
			return false
		}
	}
	return true
}
