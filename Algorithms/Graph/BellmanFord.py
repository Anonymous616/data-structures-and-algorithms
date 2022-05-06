import pandas as pd
class Graph:

    def __init__(self, v):
        self.V = v
        self.edges = []

    def addEdge(self, u, v, w):
        self.edges.append([u, v, w])

    def bellman(self, src):
        print(pd.DataFrame(self.edges, columns=['u', 'v', 'w']))
        dist = [float("Inf")] * self.V
        dist[src] = 0
        prec = [None] * self.V

        for i in range(self.V - 1):
            for u, v, w in self.edges:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    prec[v] = u

        for u, v, w in self.edges:
            if dist[v] > dist[u] + w:
                print("Graph contains negative cycle")
                return

        print(pd.DataFrame([dist,prec], columns=list(range(len(dist))), index=["Distance", "Precedence"]))

g = Graph(5)

# g.addEdge(0, 1, -1)
# g.addEdge(0, 2, 4)
# g.addEdge(1, 2, 3)
# g.addEdge(1, 3, 2)
# g.addEdge(3, 1, 1)
# g.addEdge(1, 4, 2)
# g.addEdge(4, 3, -3)

g.addEdge(0, 1, -1)
g.addEdge(0, 2, 4)
g.addEdge(1, 2, 3)
g.addEdge(1, 3, 2)
g.addEdge(1, 4, 2)
g.addEdge(3, 2, 5)
g.addEdge(3, 1, 1)
g.addEdge(4, 3, -3)

g.bellman(0)
