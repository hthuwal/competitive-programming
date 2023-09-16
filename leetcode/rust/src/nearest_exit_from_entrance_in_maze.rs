/* -------------------------------------------------------------------------- */
/*      https://leetcode.com/problems/nearest-exit-from-entrance-in-maze      */
/* -------------------------------------------------------------------------- */

use std::collections::VecDeque;

struct Solver {
    maze: Vec<Vec<char>>,
    entrance: Vec<i32>,
    n: usize,
    m: usize,
}

impl Solver {
    pub fn new(maze: Vec<Vec<char>>, entrance: Vec<i32>) -> Self {
        let n = maze.len();
        let m = maze[0].len();
        Solver {
            maze,
            entrance,
            n,
            m,
        }
    }

    fn is_valid(&mut self, i: i32, j: i32) -> bool {
        let non_neg = i >= 0 && j >= 0;

        let (i, j) = (i as usize, j as usize);
        return non_neg && i < self.n && j < self.m && self.maze[i][j] != '+';
    }

    fn is_entry(&mut self, i: i32, j: i32) -> bool {
        i == self.entrance[0] && j == self.entrance[1]
    }

    fn is_exit(&mut self, i: i32, j: i32) -> bool {
        i == 0 || j == 0 || i as usize == self.n - 1 || j as usize == self.m - 1
    }

    pub fn nearest_exit(&mut self) -> i32 {
        let dir = [0, -1, 0, 1, 0];

        // Push the entry into queue
        let mut q = VecDeque::new();
        q.push_back([self.entrance[0], self.entrance[1], 0]);

        // Mark as visited by putting up a wall
        let (sx, sy) = (self.entrance[0] as usize, self.entrance[1] as usize);
        self.maze[sx][sy] = '+';

        while let Some(top) = q.pop_front() {
            let [x, y, dist] = top;

            for i in 0..4usize {
                let (nbrx, nbry) = (x + dir[i], y + dir[i + 1]);
                if self.is_valid(nbrx, nbry) {
                    // Mark as visited by putting up a wall
                    self.maze[nbrx as usize][nbry as usize] = '+';
                    q.push_back([nbrx, nbry, dist + 1]);

                    if !self.is_entry(nbrx, nbry) && self.is_exit(nbrx, nbry) {
                        return dist + 1;
                    }
                }
            }
        }
        return -1;
    }
}
