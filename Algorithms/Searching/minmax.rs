fn max(nums: &[i32]) -> &i32 {
    let mut largest = &nums[0];
    
    for num in nums {
        if num > largest {
            largest = num;
        }
    }

    return largest;
}

fn min(nums: &[i32]) -> &i32 {
    let mut smallest = &nums[0];
    
    for num in nums {
        if num < smallest {
            smallest = num;
        }
    }

    return smallest;
}

fn main() {
    let nums: [i32; 10] = [63, 83, 16, 10, 74, 66, 17, 1, 0, 60];
    println!("Min: {} | Max: {}",min(&nums) ,max(&nums))
}
