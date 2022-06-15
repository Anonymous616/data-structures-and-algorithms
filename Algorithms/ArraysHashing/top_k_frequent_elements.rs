use std::collections::HashMap;

pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut map = HashMap::new();
    let mut freq = vec![vec![]; nums.len()];

    for &x in nums.iter() { *map.entry(x).or_insert(0) += 1; }

    for (&num, &count) in map.iter() { freq[nums.len() - count].push(num); }

    freq.into_iter().flatten().take(k as usize).collect()
}
