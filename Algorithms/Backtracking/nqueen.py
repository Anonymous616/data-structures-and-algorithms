import numpy as np
import pandas as pd

def validMove(q, col, res):
    for x in range(q):
        if res[x] == col or abs(q - x) == abs(res[x] - col):
            return False
    return True

def nqueen(q, N, res):

    for col in range(N):
        if validMove(q, col, res):
            res[q] = col

            if q == N - 1:
                combos.append(res.copy())
            else:
                nqueen(q + 1, N, res)

if __name__ == "__main__":
    N = 4

    global combos
    combos = []

    nqueen(0, N, [float("Inf")]*N)

    for res in combos:
        board = np.zeros((N, N)).astype(int)

        for i in range(len(res)):
            board[i][res[i]] = 1

        print("\nSolution")
        print(pd.DataFrame(board))
        # print(b)
