/* ------- https://leetcode.com/problems/maximum-width-of-binary-tree ------- */

package main

import (
	"container/list"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Tuple struct {
	node  *TreeNode
	hzfr  int
	depth int
}

//	                                            ┌───┐
//	                                            │   │
//	                     ┌──────────────────────┤ 0 ├───────────────────────┐
//	                     │                      │   │                       │
//	                     │                      └───┘                       │
//	                     │                                                  │
//	                     │                                                  │
//	                     │                                                  │
//	                   ┌─┴─┐                                              ┌─┴─┐
//	                   │   │                                              │   │
//	       ┌───────────┤-1 ├──────────┐                         ┌─────────┤ 1 ├───────────┐
//	       │           │   │          │                         │         │   │           │
//	       │           └───┘          │                         │         └───┘           │
//	       │                          │                         │                         │
//	       │                          │                         │                         │
//	       │                          │                         │                         │
//	       │                          │                         │                         │
//	       │                          │                         │                         │
//	     ┌─┴─┐                      ┌─┴─┐                     ┌─┴─┐                     ┌─┴─┐
//	     │   │                      │   │                     │   │                     │   │
//	┌────┤-2 ├────┐            ┌────┤-1 ├────┐           ┌────┤ 1 ├────┐           ┌────┤ 2 ├────┐
//	│    │   │    │            │    │   │    │           │    │   │    │           │    │   │    │
//	│    └───┘    │            │    └───┘    │           │    └───┘    │           │    └───┘    │
//	│             │            │             │           │             │           │             │
//
// ┌─┴─┐         ┌─┴─┐        ┌─┴─┐         ┌─┴─┐       ┌─┴─┐         ┌─┴─┐       ┌─┴─┐         ┌─┴─┐
// │   │         │   │        │   │         │   │       │   │         │   │       │   │         │   │
// │-4 │         │-3 │        │-2 │         │-1 │       │ 1 │         │ 2 │       │ 3 │         │ 4 │
// │   │         │   │        │   │         │   │       │   │         │   │       │   │         │   │
// └───┘         └───┘        └───┘         └───┘       └───┘         └───┘       └───┘         └───┘
//
// Calculate these values for each node in the tree.
// For each level keep track of the highest and lowest value.
// Find highest - lowest for each level and then maximum amongst those is the width.
type Solver struct {
	max_pdpl map[int]int
	min_ndpl map[int]int
	q        *list.List
}

func NewSolver() *Solver {
	return &Solver{
		max_pdpl: map[int]int{},
		min_ndpl: map[int]int{},
		q:        list.New(),
	}
}

func (s *Solver) updateMaps(depth, hzfr int) {
	if dist, ok := s.min_ndpl[depth]; !ok || hzfr < dist {
		s.min_ndpl[depth] = hzfr
	}

	if dist, ok := s.max_pdpl[depth]; !ok || hzfr > dist {
		s.max_pdpl[depth] = hzfr
	}
}

func (s *Solver) handleChildNodes(node_details Tuple, f func(int) (int, int)) {
	depth := node_details.depth + 1
	ld, rd := f(node_details.hzfr)
	if node_details.node.Left != nil {
		s.updateMaps(depth, ld)
		s.q.PushBack(Tuple{node_details.node.Left, ld, depth})
	}

	if node_details.node.Right != nil {
		s.updateMaps(depth, rd)
		s.q.PushBack(Tuple{node_details.node.Right, rd, depth})
	}
}

func (s *Solver) caclculateMaxWidth() int {

	ans := 0
	for l := range s.max_pdpl {
		curr_ans := s.max_pdpl[l] - s.min_ndpl[l]
		if (s.max_pdpl[l] >= 0 && s.min_ndpl[l] >= 0) || (s.min_ndpl[l] <= 0 && s.max_pdpl[l] <= 0) {
			curr_ans = curr_ans + 1
		}
		if curr_ans > ans {
			ans = curr_ans
		}
	}
	return ans
}

func (s *Solver) WidthOfBinaryTree(root *TreeNode) int {

	s.max_pdpl[0] = 0
	s.min_ndpl[0] = 0
	s.q.PushBack(Tuple{root, 0, 0})

	for s.q.Len() != 0 {
		frontElement := s.q.Front()
		front, _ := frontElement.Value.(Tuple)
		s.q.Remove(frontElement)

		if front.hzfr == 0 {
			s.handleChildNodes(front, func(i int) (int, int) { return -1, 1 })
		} else if front.hzfr < 0 {
			s.handleChildNodes(front, func(i int) (int, int) { return 2 * i, 2*i + 1 })
		} else {
			s.handleChildNodes(front, func(i int) (int, int) { return 2*i - 1, 2 * i })
		}

	}
	return s.caclculateMaxWidth()
}
