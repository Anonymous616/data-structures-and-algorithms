func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func characterReplacement(s string, k int) int {
    count := map[rune]int {}
    res := 0

    maxCount := 0

    l := 0

    for r, c := range s {
        count[c] += 1
        maxCount = Max(maxCount, count[c])

        if (r - l + 1) - maxCount > k {
            count[rune(s[l])] -= 1
            l += 1
        }

        res = Max(res, r - l + 1)
    }

    return res
}
