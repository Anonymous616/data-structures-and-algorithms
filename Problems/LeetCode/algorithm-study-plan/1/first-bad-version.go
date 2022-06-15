// https://leetcode.com/problems/first-bad-version/
/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
    beg, end := 1, n

    for beg < end {
        mid := beg + (end - beg) / 2

        if isBadVersion(mid) {
            end = mid
        } else {
            beg = mid + 1
        }
    }

    return beg
}
