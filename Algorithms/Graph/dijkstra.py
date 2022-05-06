import sys
import numpy as np

class Graph():
    def __init__(self, v):
        self.V = v
        self.graph = np.zeros((v,v))

    def print(self, dist, prec):
        print("Vertex\tDistance\tPrec")
        for node in range(self.V):
            print(f"{node}\t{dist[node]}\t\t{prec[node]}")

    def minDist(self, dist, sptSet):
        minD = float("Inf")
        minDindex = -1

        for u in range(self.V):
            if dist[u] < minD and sptSet[u] == False:
                minD = dist[u]
                minDindex = u

        return minDindex

    def dijkstra(self, src):
        dist = [float("Inf")] * self.V
        prec = [float("Inf")] * self.V
        sptSet = [False] * self.V

        dist[src] = 0

        for i in range(self.V):
            # self.print(dist, prec)

            u = self.minDist(dist, sptSet)
            sptSet[u] = True

            for v in range(self.V):
                # check if its connected, check if not selected and check if new size is better
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]:
                    dist[v] = dist[u] + self.graph[u][v]
                    prec[v] = u

        self.print(dist, prec)

if __name__ == "__main__":
    g = Graph(4)
    g.graph = np.array([
        [0, 4, 10, 2],
        [4, 0, 4, 0],
        [10, 4, 0, 3],
        [2, 0, 3, 0],
    ])
    print(g.graph)
    g.dijkstra(0)
