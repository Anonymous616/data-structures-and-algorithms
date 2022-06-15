// https://leetcode.com/problems/contains-duplicate/
use std::collections::HashSet;

pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut numSet = HashSet::new();

    for n in nums {
        if !numSet.insert(n) { return true; }
    }

    false
}
