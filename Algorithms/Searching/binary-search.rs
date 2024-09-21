fn binary_search(nums: &[i32], target: i32) -> Option<usize> {
    let (mut beg, mut end): (usize, usize) = (0, nums.len() - 1);

    while beg <= end {
        let mid: usize = (beg + end) / 2;

        if nums[mid] == target {
            return Some(mid)
        }

        if nums[mid] > target {
            end = mid - 1;
        } else {
            beg = mid + 1
        }
    }

    return None
}

fn main() {
    let nums: [i32; 10] = [63, 83, 16, 10, 74, 66, 17, 1, 0, 60];

    let target = 63;
    match binary_search(&nums, target) {
        Some(num) => println!("{target} found at {num}"),
        None => println!("Not found"),
    }
}
