fn selection_sort(nums: &mut [i32]) {
    for i in 0..(nums.len() - 1) {
        let mut mn = (nums[i], i); 
        for j in (i+1)..nums.len() {
            if nums[j] < mn.0 {
                mn = (nums[j], j);
            }
        }
        nums.swap(i, mn.1);
    }
}

fn main() {
    let mut nums: [i32; 10] = [63, 83, 16, 10, 74, 66, 17, 1, 0, 60];
    selection_sort(&mut nums);
    println!("Sorted: {:?}", nums);
}
