/* -------------------------------------------------------------------------- */
/*         https://leetcode.com/problems/longest-consecutive-sequence/        */
/* -------------------------------------------------------------------------- */

use std::collections::{HashMap, HashSet};

pub fn find_largest_connected_component(graph: HashMap<i32, Vec<i32>>) -> i32 {
    let mut visited: HashSet<i32> = HashSet::new();

    let mut ans = 0;
    for each in graph.iter() {
        if visited.contains(each.0) {
            continue;
        }

        let mut size = 0;
        let mut st = Vec::new();
        st.push(each.0);
        while let Some(top) = st.pop() {
            visited.insert(*top);
            size += 1;
            for nbr in graph[top].iter() {
                if !visited.contains(nbr) {
                    st.push(nbr)
                }
            }
        }

        if size > ans {
            ans = size;
        }
    }
    ans
}

pub fn insert_if_not_present(list: &mut Vec<i32>, n: i32) {
    for each in list.iter() {
        if *each == n {
            return;
        }
    }
    list.push(n)
}

pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
    let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();

    for num in nums.iter() {
        let prev = num - 1;
        let after = num + 1;

        if !graph.contains_key(num) {
            graph.insert(*num, Vec::with_capacity(2));
        }

        if graph.contains_key(&prev) {
            insert_if_not_present(graph.get_mut(num).unwrap(), prev);
            insert_if_not_present(graph.get_mut(&prev).unwrap(), *num);
        }

        if graph.contains_key(&after) {
            insert_if_not_present(graph.get_mut(num).unwrap(), after);
            insert_if_not_present(graph.get_mut(&after).unwrap(), *num);
        }
    }
    find_largest_connected_component(graph)
}
