/* -------------------------------------------------------------------------- */
/*                 https://leetcode.com/problems/unique-paths                 */
/* -------------------------------------------------------------------------- */

pub fn unique_paths(m: i32, n: i32) -> i32 {
    let mut first_row = vec![1; n as usize];

    for i in 1..m as usize {
        let mut second_row_prev_val = first_row[0];
        for j in 1..n as usize {
            first_row[j] += second_row_prev_val;
            second_row_prev_val = first_row[j];
        }
    }

    *first_row.last().unwrap()
}