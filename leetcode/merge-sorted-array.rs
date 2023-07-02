/* -------------------------------------------------------------------------- */
/*              https://leetcode.com/problems/merge-sorted-array/             */
/* -------------------------------------------------------------------------- */

fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
    let mut i = m - 1;
    let mut j = n - 1;
    let mut k = m + n - 1;

    while i >= 0 && j >= 0 {
        if nums1[i as usize] >= nums2[j as usize] {
            nums1[k as usize] = nums1[i as usize];
            i -= 1;
            k -= 1;
        } else {
            nums1[k as usize] = nums2[j as usize];
            j -= 1;
            k -= 1;
        }
    }

    while i >= 0 {
        nums1[k as usize] = nums1[i as usize];
        i -= 1;
        k -= 1;
    }

    while j >= 0 {
        nums1[k as usize] = nums2[j as usize];
        j -= 1;
        k -= 1;
    }
}

fn main() {
    let mut vec1 = vec![1, 2, 6, 0, 0];
    let mut vec2 = vec![3, 4];
    merge(&mut vec1, 3, &mut vec2, 2);
    println!("{:?}", vec1);
}
