fn quick_sort(nums: &mut [i32], start: usize, end: usize) {
    if start >= end {
        return;
    }

    let pivot = nums[end];
    let mut i = start;

    for j in start..end {
        if nums[j] <= pivot {
            nums.swap(i, j);
            i += 1;
        }
    }
    nums.swap(i, end);

    if i > 0 {
        quick_sort(nums, start, i - 1);
    }
    quick_sort(nums, i + 1, end);
}

fn main() {
    let mut nums: [i32; 10] = [63, 83, 16, 10, 74, 66, 17, 1, 0, 60];
    quick_sort(&mut nums, 0, 9);
    println!("Sorted: {:?}", nums);
}
