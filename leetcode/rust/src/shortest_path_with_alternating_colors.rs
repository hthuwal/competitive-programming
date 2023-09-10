use std::collections::VecDeque;

struct Solver {
    red_graph: Vec<Vec<usize>>,
    blue_graph: Vec<Vec<usize>>,
    distance_via_blue: Vec<i32>,
    distance_via_red: Vec<i32>,
    num_nodes: usize,
}

enum Color {
    Red,
    Blue,
}

impl Solver {
    pub fn new(n: i32, red_edges: Vec<Vec<i32>>, blue_edges: Vec<Vec<i32>>) -> Self {
        let num_nodes = n as usize;
        let mut solver = Solver {
            red_graph: vec![vec![]; num_nodes],
            blue_graph: vec![vec![]; num_nodes],
            distance_via_blue: vec![i32::MAX; num_nodes],
            distance_via_red: vec![i32::MAX; num_nodes],
            num_nodes,
        };

        for edge in red_edges.iter() {
            solver.red_graph[edge[0] as usize].push(edge[1] as usize);
        }

        for edge in blue_edges.iter() {
            solver.blue_graph[edge[0] as usize].push(edge[1] as usize);
        }

        solver
    }

    fn bfs(&mut self) {
        let mut q = VecDeque::new();

        // Assume you reached 0th node via red edge
        q.push_back((0usize, Color::Red));
        self.distance_via_red[0] = 0;

        // Assume you reached 0th node via blue edge
        q.push_back((0, Color::Blue));
        self.distance_via_blue[0] = 0;

        while let Some((node, came_via)) = q.pop_front() {
            match came_via {
                Color::Blue => {
                    let nbr_new_dist = self.distance_via_blue[node] + 1;

                    // You'll have to go nbrs via red edge
                    for nbr in self.red_graph[node].iter() {
                        if nbr_new_dist < self.distance_via_red[*nbr] {
                            q.push_back((*nbr, Color::Red));
                            self.distance_via_red[*nbr] = nbr_new_dist
                        }
                    }
                }
                Color::Red => {
                    let nbr_new_dist = self.distance_via_red[node] + 1;

                    // You'll have to go nbrs via blue edge
                    for nbr in self.blue_graph[node].iter() {
                        if nbr_new_dist < self.distance_via_blue[*nbr] {
                            q.push_back((*nbr, Color::Blue));
                            self.distance_via_blue[*nbr] = nbr_new_dist;
                        }
                    }
                }
            }
        }
    }

    pub fn solve(&mut self) -> Vec<i32> {
        self.bfs();
        let mut distances = vec![-1; self.num_nodes];

        for i in 0..self.num_nodes {
            let dist = std::cmp::min(self.distance_via_blue[i], self.distance_via_red[i]);
            if dist != i32::MAX {
                distances[i] = dist;
            }
        }

        distances
    }
}
