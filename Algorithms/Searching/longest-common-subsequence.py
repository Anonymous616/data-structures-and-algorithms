import numpy as np
import pandas as pd

def lcs(x, y):
    m = len(x)
    n = len(y)
    L = np.zeros((m+1, n+1))

    for i in range(1, m+1):
        for j in range(1, n+1):
            if x[i-1] == y[j-1]:
                L[i, j] = L[i-1, j-1] + 1
            else:
                L[i, j] = max(L[i-1, j], L[i, j-1])

    # print(pd.DataFrame(L))
    print(pd.DataFrame(L, columns=[0]+list(y), index=[0]+list(x)))

    lcs = ""

    i = m
    j = n
    while i > 0 and j > 0:
        if L[i-1, j-1] == L[i, j]:
            i -= 1
        elif L[i-1, j] == L[i, j-1]:
            lcs += X[i-1]
            i -= 1
            j -= 1
        elif L[i-1, j] > L[i, j-1]:
            i -= 1
        else:
            j -= 1

    return lcs[::-1]

if __name__ == "__main__":
    X = "abbacdba"
    Y = "abda"
    print(lcs(X, Y))
