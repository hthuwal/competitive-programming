// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

use std::collections::{HashMap, VecDeque};

pub fn make_connected(n: i32, connections: Vec<Vec<i32>>) -> i32 {
    // If the number of edges is less than n-1, then it is impossible to connect all the nodes.
    if connections.len() < n as usize - 1 {
        return -1;
    }

    // Create an Adjacency list representation for O(1) edge access
    let mut edge_map: HashMap<usize, Vec<usize>> = HashMap::new();
    for edge in connections.iter() {
        edge_map.entry(edge[0] as usize).or_default().push(edge[1] as usize);
        edge_map.entry(edge[1] as usize).or_default().push(edge[0] as usize);
    }

    // Find the number of connected components
    let mut visited = vec![false; n as usize];
    let mut num_components = 0;

    for idx in 0..visited.len() {
        if visited[idx] {
            continue;
        }
        num_components += 1;

        // Preform BFS starting from this node
        let mut queue = VecDeque::new();
        queue.push_back(idx);
        visited[idx] = true;

        while let Some(front) = queue.pop_front() {
            for nbr in edge_map.entry(front).or_default().iter() {
                if !visited[*nbr] {
                    queue.push_back(*nbr);
                    visited[*nbr] = true;
                }
            }
        }
    }

    // We just need to connect all components
    return num_components - 1;
}
