use std::cmp::{max, min, Reverse};
use std::collections::BinaryHeap;
use std::vec;

/* -------------------------------------------------------------------------- */
/*             https://leetcode.com/problems/trapping-rain-water/             */
/* -------------------------------------------------------------------------- */
pub fn trap_1d(height: Vec<i32>) -> i32 {
    let mut max_left = vec![0i32; height.len()];
    let mut max_right = vec![0i32; height.len()];

    for i in 1..height.len() {
        max_left[i] = max(max_left[i - 1], height[i - 1]);
    }

    for i in (0..height.len() - 1).rev() {
        max_right[i] = max(max_right[i + 1], height[i + 1]);
    }

    let mut total_water = 0i32;
    for i in 1..height.len() - 1 {
        let min_max_height = min(max_left[i], max_right[i]);
        if min_max_height > height[i] {
            total_water += min_max_height - height[i];
        }
    }

    return total_water;
}

/* -------------------------------------------------------------------------- */
/*            https://leetcode.com/problems/trapping-rain-water-ii            */
/* -------------------------------------------------------------------------- */

// Gredy: Idea
// Min heap of height of all the border items
// Any adjacent cells lower than it will hold the water = the difference in their height
// https://www.geeksforgeeks.org/trapping-rain-water-in-a-matrix/
pub fn trap_2d(height_map: Vec<Vec<i32>>) -> i32 {
    let n = height_map.len();
    let m = height_map[0].len();

    if n == 1 {
        return 0;
    }

    let nbrs = vec![(-1i32, 0i32), (0, 1), (1, 0), (0, -1)];

    let mut visited = vec![vec![false; m]; n];

    // Min Heap Of (height, i, j)
    let mut heap = BinaryHeap::new();

    for i in 0..n {
        heap.push((Reverse(height_map[i][0]), i, 0));
        visited[i][0] = true;
        if m > 1 {
            heap.push((Reverse(height_map[i][m - 1]), i, m - 1));
            visited[i][m - 1] = true;
        }
    }

    for j in 0..m {
        heap.push((Reverse(height_map[0][j]), 0, j));
        visited[0][j] = true;
        if n > 1 {
            heap.push((Reverse(height_map[n - 1][j]), n - 1, j));
            visited[n - 1][j] = true;
        }
    }

    let mut total_water = 0i32;
    let mut max_height_till_now = 0i32;

    while let Some(top) = heap.pop() {
        max_height_till_now = max(max_height_till_now, top.0 .0);
        let (_, curx, cury) = top;

        for nbr in nbrs.iter() {
            let nbrx = curx as i32 + nbr.0;
            let nbry = cury as i32 + nbr.1;

            if nbrx < 0 || nbry < 0 || nbrx >= n as i32 || nbry >= m as i32 {
                continue;
            }

            let nbrx = nbrx as usize;
            let nbry = nbry as usize;

            if visited[nbrx][nbry] {
                continue;
            }

            let nbr_height = height_map[nbrx][nbry];
            if max_height_till_now > nbr_height {
                total_water += max_height_till_now - nbr_height;
            }

            heap.push((Reverse(nbr_height), nbrx, nbry));
            visited[nbrx][nbry] = true;
        }
    }
    return total_water;
}
