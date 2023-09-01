/* ------- https://leetcode.com/problems/maximum-width-of-binary-tree ------- */

use std::cell::RefCell;
use std::collections::{HashMap, VecDeque};
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct NodeDetails {
    node: Rc<RefCell<TreeNode>>,
    depth: i32,
    hzfr: i32,
}

struct Solver {
    max_pdpl: HashMap<i32, i32>,
    min_ndpl: HashMap<i32, i32>,
    q: VecDeque<NodeDetails>,
}

//                                               ┌───┐
//                                               │   │
//                        ┌──────────────────────┤ 0 ├───────────────────────┐
//                        │                      │   │                       │
//                        │                      └───┘                       │
//                        │                                                  │
//                        │                                                  │
//                        │                                                  │
//                      ┌─┴─┐                                              ┌─┴─┐
//                      │   │                                              │   │
//          ┌───────────┤-1 ├──────────┐                         ┌─────────┤ 1 ├───────────┐
//          │           │   │          │                         │         │   │           │
//          │           └───┘          │                         │         └───┘           │
//          │                          │                         │                         │
//          │                          │                         │                         │
//          │                          │                         │                         │
//          │                          │                         │                         │
//          │                          │                         │                         │
//        ┌─┴─┐                      ┌─┴─┐                     ┌─┴─┐                     ┌─┴─┐
//        │   │                      │   │                     │   │                     │   │
//   ┌────┤-2 ├────┐            ┌────┤-1 ├────┐           ┌────┤ 1 ├────┐           ┌────┤ 2 ├────┐
//   │    │   │    │            │    │   │    │           │    │   │    │           │    │   │    │
//   │    └───┘    │            │    └───┘    │           │    └───┘    │           │    └───┘    │
//   │             │            │             │           │             │           │             │
// ┌─┴─┐         ┌─┴─┐        ┌─┴─┐         ┌─┴─┐       ┌─┴─┐         ┌─┴─┐       ┌─┴─┐         ┌─┴─┐
// │   │         │   │        │   │         │   │       │   │         │   │       │   │         │   │
// │-4 │         │-3 │        │-2 │         │-1 │       │ 1 │         │ 2 │       │ 3 │         │ 4 │
// │   │         │   │        │   │         │   │       │   │         │   │       │   │         │   │
// └───┘         └───┘        └───┘         └───┘       └───┘         └───┘       └───┘         └───┘
//
// Calculate these values for each node in the tree.
// For each level keep track of the highest and lowest value.
// Find highest - lowest for each level and then maximum amongst those is the width.
impl Solver {
    pub fn new() -> Self {
        Solver {
            max_pdpl: HashMap::new(),
            min_ndpl: HashMap::new(),
            q: VecDeque::new(),
        }
    }

    pub fn width_of_binary_tree(&mut self, root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        self.max_pdpl.insert(0, 0);
        self.min_ndpl.insert(0, 0);
        self.q.push_back(NodeDetails {
            node: root.unwrap(),
            depth: 0,
            hzfr: 0,
        });

        while let Some(front) = self.q.pop_front() {
            if front.hzfr == 0 {
                self.handle_children(&front, |_| (-1, 1));
            } else if front.hzfr < 0 {
                self.handle_children(&front, |x| (2 * x, 2 * x + 1));
            } else {
                self.handle_children(&front, |x| (2 * x - 1, 2 * x));
            }
        }

        return self.calculate_max_width();
    }

    fn calculate_max_width(&self) -> i32 {
        let levels = self.max_pdpl.len() as i32;
        let mut ans = 0;
        for i in 0..levels {
            let same_side_of_root: bool = (self.max_pdpl[&i] >= 0 && self.min_ndpl[&i] >= 0)
                || (self.max_pdpl[&i] < 0 && self.min_ndpl[&i] < 0);

            let mut cur_ans = self.max_pdpl[&i] - self.min_ndpl[&i];
            if same_side_of_root {
                cur_ans += 1;
            }

            if cur_ans > ans {
                ans = cur_ans;
            }
        }
        return ans;
    }

    fn handle_children(
        &mut self,
        node_details: &NodeDetails,
        hzfr_calc: impl Fn(i32) -> (i32, i32),
    ) {
        let depth = node_details.depth + 1;
        let (ld, rd) = hzfr_calc(node_details.hzfr);

        if let Some(left) = node_details.node.borrow().left.clone() {
            self.update_level_maps(depth, ld);
            self.q.push_back(NodeDetails {
                node: left,
                depth,
                hzfr: ld,
            });
        }

        if let Some(right) = node_details.node.borrow().right.clone() {
            self.update_level_maps(depth, rd);
            self.q.push_back(NodeDetails {
                node: right,
                depth,
                hzfr: rd,
            });
        }
    }

    fn update_level_maps(&mut self, depth: i32, dist: i32) {
        let value = self.max_pdpl.entry(depth).or_insert(dist);
        *value = if dist > *value { dist } else { *value };

        let value = self.min_ndpl.entry(depth).or_insert(dist);
        *value = if dist < *value { dist } else { *value };
    }
}
