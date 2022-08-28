/* -------------------------------------------------------------------------- */
/*                    https://leetcode.com/problems/powx-n                    */
/* -------------------------------------------------------------------------- */

fn my_pow(x: f64, n: i32) -> f64 {
    let mut ans: f64 = 1.0;
    let mut num = x;
    let mut p = n;
    while p != 0 {
        if p & 1 == 1 {
            if p > 0 {
                ans = ans * num;
            } else {
                ans = ans / num;
            }
        }

        num = num * num;
        p = p / 2;
    }
    ans
}

fn main() {
    println!("{}", my_pow(2.0, 10));
}
