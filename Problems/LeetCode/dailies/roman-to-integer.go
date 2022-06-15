func romanToInt(s string) int {
    symap := map[byte]int {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }

    res := 0

    for i, c  := range s {
        if i + 1 < len(s) && symap[s[i]] < symap[s[i + 1]] {
            res -= symap[byte(c)]
        } else {
            res += symap[byte(c)]
        }
    }

    return res;
}
