## Problem

[how-many-numbers-are-smaller-than-the-current-number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/)

## Solution

```go
func smallerNumbersThanCurrent(nums []int) []int {
    // Store counts of each entry
    hash := [101]int{}
    for _, num := range nums {
        hash[num]++
    }
    
    // Make cumulative 
    for i := 1; i < 101; i++ {
        hash[i] += hash[i-1]
    }
    
    ans := make([]int,  len(nums), len(nums))
    for i, num := range nums {
        if num > 0 {
            ans[i] = hash[num-1]
        }
    }
    return ans
}
```