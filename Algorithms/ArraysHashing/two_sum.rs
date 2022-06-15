// https://leetcode.com/problems/two-sum/
use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut nMap : HashMap<i32, i32> = HashMap::new();

    for i in 0..nums.len() {
        let rem : i32 = target - nums[i];

        if nMap.contains_key(&rem) {
            return vec![*nMap.get_mut(&rem).unwrap(), i as i32];
        }

        nMap.insert(nums[i].clone(), i as i32);
    }

    vec![]
}
