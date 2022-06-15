impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
      use std:: collections::HashMap;
      let mut char_map: HashMap<char, i32> = HashMap::new();
      let mut i: i32 = 0;
      let mut closest_repeat: i32 = -1;
      let mut count: i32 = 0;
      let mut longest: i32 = 0;

      for c in s.chars() {
        if char_map.contains_key(&c) {
          let last_seen: &mut i32 = char_map.get_mut(&c).unwrap();

          if closest_repeat < *last_seen {
            closest_repeat = last_seen.clone();
            if longest < count { longest = count.clone() }
            count = i - closest_repeat;

          } else {
            count = count + 1;
            if longest < count { longest = count.clone() }

          }

          *last_seen = i.clone();

        } else {
          char_map.insert(c, i.clone());
          count = count + 1;
          if longest < count { longest = count.clone() }
        }

        i = i + 1;
      }
      longest
    }
}
