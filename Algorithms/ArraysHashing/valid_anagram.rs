// https://leetcode.com/problems/valid-anagram/
use std::collections::HashMap;

pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    let mut map = HashMap::new();

    for s in strs {
        let mut arr = [0; 26];

        s.chars().for_each(|c| (arr[c as usize - 'a' as usize] += 1));

        (*map.entry(arr).or_insert(vec![])).push(s.to_string());

    }
    map.into_values().collect()
}
