/* -------------------------------------------------------------------------- */
/*                   https://leetcode.com/problems/two-sum/                   */
/* -------------------------------------------------------------------------- */

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut i = 0;
    let mut j = nums.len() - 1;

    if nums.len() == 2 {
        return vec![0, 1];
    }

    let mut sorted_vec = Vec::with_capacity(nums.len());
    for (idx, val) in nums.iter().enumerate() {
        sorted_vec.push((val, idx as i32));
    }

    sorted_vec.sort_by_key(|k| k.0);
    while i < j {
        let sum = sorted_vec[i].0 + sorted_vec[j].0;
        if sum == target {
            return vec![sorted_vec[i].1, sorted_vec[j].1];
        } else if sum < target {
            i += 1;
        } else {
            j -= 1;
        }
    }

    return vec![];
}

fn main() {
    println!("{:?}", two_sum(vec![3, 2, 4], 6));
}
