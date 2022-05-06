def genLps(pattern):
    lps = [0] * (len(pattern)+1)
    i = 1

    lpsLen = 0

    while i < len(pattern):
        if pattern[i] == pattern[lpsLen]:
            lpsLen += 1
            lps[i] = lpsLen
            i += 1
        else:
            if lpsLen != 0:
                lpsLen = lps[lpsLen - 1]
            else:
                lps[i] = 0
                i += 1

    return lps

def kmp(txt, pattern):
    lps = genLps(pattern)

    i = 0
    j = 0

    while i < len(txt):
        if pattern[j] == txt[i]:
            i += 1
            j += 1

        if  j == len(pattern):
            print(f"Found pattern at index {i-j}")
            j = lps[j-1]

        elif i < len(txt) and pattern[j] != txt[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1

kmp("ababdabacdababcabab", "ababcabab")
