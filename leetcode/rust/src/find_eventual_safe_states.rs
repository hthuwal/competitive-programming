/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/find-eventual-safe-states          */
/* -------------------------------------------------------------------------- */

use std::vec;

#[derive(Clone, PartialEq, Debug)]
enum State {
    SAFE,
    UNSAFE,
    UNKNOWN,
}

pub struct SolverDFS {
    visited: Vec<bool>,
    states: Vec<State>,
    graph: Vec<Vec<i32>>,
}

impl SolverDFS {
    pub fn new(graph: Vec<Vec<i32>>) -> Self {
        let n = graph.len();
        SolverDFS {
            visited: vec![false; n],
            states: vec![State::UNKNOWN; n],
            graph,
        }
    }

    fn dfs(&mut self, node: i32) {
        let node = node as usize;
        // If this has already been visited
        if self.visited[node] {
            // If the state of this is unknown ==> Loop
            if self.states[node] == State::UNKNOWN {
                self.states[node] = State::UNSAFE
            }
            return;
        }

        // Do DFS for all the nbrs
        self.visited[node] = true;
        for i in 0..self.graph[node].len() {
            let nbr = self.graph[node][i];
            self.dfs(nbr)
        }

        // If at least one of my nbr is unsafe, i am unsafe
        for nbr in self.graph[node].iter() {
            if self.states[*nbr as usize] == State::UNSAFE {
                self.states[node] = State::UNSAFE;
                return;
            }
        }

        self.states[node] = State::SAFE
    }

    pub fn solve(&mut self) -> Vec<i32> {
        // Do DFS for all the nodes in the graph that haven't been visited yet
        for i in 0..self.graph.len() {
            if !self.visited[i] {
                self.dfs(i as i32)
            }
        }

        let mut ans = vec![];
        for i in 0..self.graph.len() {
            if self.states[i] == State::SAFE {
                ans.push(i as i32)
            }
        }
        ans
    }
}
