pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
    let n = nums.len();
    let mut res = vec![1; n];
    let mut p = 1;

    for i in 0..n {
        res[i] = p;
        p *= nums[i];
    }

    p = 1;
    for i in (0..n).rev() {
        res[i] *= p;
        p *= nums[i];
    }

    res
}
