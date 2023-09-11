/* -------------------------------------------------------------------------- */
/*      https://leetcode.com/problems/time-needed-to-inform-all-employees     */
/* -------------------------------------------------------------------------- */

use std::collections::HashMap;

struct Solver {
    n: i32,
    head_id: i32,
    manager: Vec<i32>,
    inform_time: Vec<i32>,
    memory: HashMap<usize, i32>,
}

impl Solver {
    pub fn new(n: i32, head_id: i32, manager: Vec<i32>, inform_time: Vec<i32>) -> Self {
        Solver {
            n,
            head_id,
            manager,
            inform_time,
            memory: HashMap::new(),
        }
    }

    fn calculate_time(&mut self, e: usize) -> i32 {
        if e == self.head_id as usize {
            return 0;
        }

        let manager = self.manager[e as usize] as usize;
        if let Some(t) = self.memory.get(&e) {
            return *t;
        }

        let value = self.calculate_time(manager) + self.inform_time[manager];
        self.memory.insert(e, value);
        value
    }

    pub fn num_of_minutes(&mut self) -> i32 {
        for i in 0..self.n as usize {
            self.calculate_time(i);
        }

        *self.memory.values().max().unwrap_or(&0)
    }
}
