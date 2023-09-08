/* ------------ https://leetcode.com/problems/number-of-provinces ----------- */

pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
    let num_nodes = is_connected.len();
    let mut visited = vec![false; num_nodes];

    let mut num_components = 0;
    for node in 0..num_nodes {
        if visited[node] {
            continue;
        }

        num_components += 1;
        let mut stack = vec![];
        stack.push(node);
        while let Some(top) = stack.pop() {
            visited[top] = true;
            for nbr in 0..num_nodes {
                if nbr != node && !visited[nbr] && is_connected[top][nbr] == 1 {
                    stack.push(nbr)
                }
            }
        }
    }

    num_components
}
