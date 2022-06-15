// https://leetcode.com/problems/binary-search/
func search(nums []int, target int) int {
    beg := 0
    end := len(nums) - 1

    for beg <= end {
        mid := (beg + end) / 2

        if nums[mid] == target { return mid }

        if nums[mid] < target {
            beg = mid + 1
        } else if nums[mid] > target {
            end = mid - 1;
        }
    }

    return -1
}
