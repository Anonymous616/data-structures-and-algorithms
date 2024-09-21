fn bubble_sort(nums: &mut [i32]) {
    for i in 0..(nums.len() - 1) {
        for j in (i + 1)..(nums.len() - 1) {
            if nums[i] > nums[j] {
                nums.swap(i, j)
            }
        }
    }
}

fn main() {
    let mut nums: [i32; 10] = [63, 83, 16, 10, 74, 66, 17, 1, 0, 60];
    bubble_sort(&mut nums);
    println!("Sorted: {:?}", nums);
}
