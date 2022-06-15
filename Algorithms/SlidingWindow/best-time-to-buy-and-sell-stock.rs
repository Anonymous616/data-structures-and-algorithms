use std::cmp;

pub fn max_profit(prices: Vec<i32>) -> i32 {
    let mut left = 0;
    let mut res = 0;

    for right in 0..prices.len() {
        if prices[left] > prices[right] { left = right; }

        res = cmp::max(res, prices[right] - prices[left]);
    }

    res
}
