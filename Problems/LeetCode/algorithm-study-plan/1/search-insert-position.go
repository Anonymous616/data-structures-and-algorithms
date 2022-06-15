// https://leetcode.com/problems/search-insert-position/
func searchInsert(nums []int, target int) int {
    beg, end := 0, len(nums) - 1
    var mid int

    for beg <= end {
        mid = beg + (end - beg) / 2

        if nums[mid] == target { return mid }

        if nums[mid] < target {
            beg = mid + 1
        } else if nums[mid] > target {
            end = mid - 1;
        }
    }

    return beg
}
