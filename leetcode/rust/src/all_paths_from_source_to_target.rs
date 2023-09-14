/* -------------------------------------------------------------------------- */
/*        https://leetcode.com/problems/all-paths-from-source-to-target       */
/* -------------------------------------------------------------------------- */
pub struct Solver {
    graph: Vec<Vec<i32>>,
}

impl Solver {
    pub fn new(graph: Vec<Vec<i32>>) -> Self {
        Solver { graph }
    }

    // 10ms, 14.8 MB
    // Beats 15%
    pub fn solve_recursive(&self, v: i32) -> Vec<Vec<i32>> {
        if v as usize == self.graph.len() - 1 {
            vec![vec![v]]
        } else {
            let mut paths_from_v: Vec<Vec<i32>> = Vec::new();
            for nbr in self.graph[v as usize].iter() {
                paths_from_v.append(&mut self.solve_recursive(*nbr));
            }

            for path in paths_from_v.iter_mut() {
                path.insert(0, v);
            }

            paths_from_v
        }
    }

    // 2ms, 3MB
    // Beats 100%
    pub fn solver_iterative(&self) -> Vec<Vec<i32>> {
        let target = self.graph.len() - 1;

        let mut paths: Vec<Vec<i32>> = Vec::new();
        let mut stack: Vec<Vec<i32>> = Vec::new();
        stack.push(vec![0]);

        while let Some(top_path) = stack.pop() {
            let last_node = top_path.last().unwrap();
            for nbr in self.graph[*last_node as usize].iter() {
                let mut path = top_path.clone();
                path.push(*nbr);

                if *nbr as usize == target {
                    paths.push(path)
                } else {
                    stack.push(path)
                }
            }
        }

        paths
    }
}
