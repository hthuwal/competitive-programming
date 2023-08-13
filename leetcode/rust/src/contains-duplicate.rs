/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/contains-duplicate              */
/* -------------------------------------------------------------------------- */

use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hs = HashSet::new();
        for num in nums {
            if !hs.insert(num) {
                return true;
            }
        }
        return false;
    }
}
