import numpy as np


def findLeast(P, u, v, N):
    res = []

    for i in range(1, N):
        if i == u or i == v:
            continue
        if P[u, i] != 0:
            res.append(P[u, i])
        if P[i, v] != 0:
            res.append(P[i, v])

    return res


def sum_it(N, M, edges):
    output = []

    P = np.zeros((N+1, N+1))

    for i in edges:
        P[i[0], i[1]] = i[2]

    # print(P)

    for x in range(len(edges)):
        u, v, w = edges[x]
        res = findLeast(P, u, v, N)
        # print(res)
        # print(max(w, min(res)))
        output.append(max(w, min(res) if len(res) > 0 else w))

    return sum(output)


N = 3
M = 3
edges = [[1, 2, 4], [1, 3, 2], [2, 3, 5]]

out_ = sum_it(N, M, edges)
print(out_)
