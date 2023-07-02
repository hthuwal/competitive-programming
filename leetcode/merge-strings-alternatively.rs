/* -------------------------------------------------------------------------- */
/*           https://leetcode.com/problems/merge-strings-alternately          */
/* -------------------------------------------------------------------------- */

pub fn merge_alternately(word1: String, word2: String) -> String {
    let n = word1.len();
    let m = word2.len();

    let mut res = String::with_capacity(n + m);

    let mut i = 0usize;
    let mut j = 0usize;

    while i < n && j < m {
        res.push_str(word1.get(i..i + 1).unwrap());
        res.push_str(word2.get(j..j + 1).unwrap());
        i += 1;
        j += 1;
    }

    while i < n {
        res.push_str(word1.get(i..i + 1).unwrap());
        i += 1
    }

    while j < m {
        res.push_str(word2.get(j..j + 1).unwrap());
        j += 1;
    }
    res
}

fn main() {
    println!(
        "{}",
        merge_alternately("john".to_string(), "doe".to_string())
    );
}
