func charIndex(c byte) int {
    return int(c - byte('a'))
}

func checkInclusion(s1 string, s2 string) bool {
    if len(s1) > len(s2) { return false }

    var s1Count, s2Count [26]int

    for i := range s1 {
        s1Count[charIndex(s1[i])] += 1
        s2Count[charIndex(s2[i])] += 1
    }

    matches := 0

    for i := 0; i < 26; i++ {
        if s1Count[i] == s2Count[i] {
            matches += 1
        }
    }

    l := 0
    for r := len(s1); r < len(s2); r++ {
        if matches == 26 { return true }

        i := charIndex(s2[r])
        s2Count[i]++
        if s1Count[i] == s2Count[i] {
            matches++
        } else if s1Count[i] + 1 == s2Count[i] {
            matches--
        }

        i = charIndex(s2[l])
        s2Count[i]--
        if s1Count[i] == s2Count[i] {
            matches++
        } else if s1Count[i] - 1 == s2Count[i] {
            matches--
        }

        l++
    }

    return matches == 26
}
