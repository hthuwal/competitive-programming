/* -------------------------------------------------------------------------- */
/*                https://leetcode.com/problems/delete-and-earn               */
/* -------------------------------------------------------------------------- */

pub fn delete_and_earn(nums: Vec<i32>) -> i32 {
    let max = *nums.iter().max().unwrap() as usize;

    let mut freq = vec![0i32; max + 1];
    nums.iter().for_each(|x| freq[*x as usize] += 1);

    for i in 2..(max + 1usize) {
        freq[i] = std::cmp::max(i as i32 * freq[i] + freq[i - 2], freq[i - 1]);
    }

    return *freq.last().unwrap();
}
