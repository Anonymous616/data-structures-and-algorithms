import sys

class Graph():
    def __init__(self, v, graph):
        self.V = v
        self.graph = graph

    def printRes(self, prec):
        print("Edge\tWeight")
        for i in range(1, len(prec)):
            print(f"{prec[i]} - {i}\t{self.graph[i][prec[i]]}")

    def minKey(self, key, visited):
        min = sys.maxsize
        minIndex = -1

        for v in range(self.V):
            # check if distance in minimum and node is not selected
            if key[v] < min and visited[v] == False:
                min = key[v]
                minIndex = v

        return minIndex

    def prims(self):
        key = [sys.maxsize] * self.V # for picking min cost
        prec = [None] * self.V # for printin result
        visited = [False] * self.V # to know which vertices are selected

        key[0] = 0
        prec[0] = None # Set first node as root

        for count in range(self.V):
            u = self.minKey(key, visited) # find min distance vertex
            visited[u] = True
            for v in range(self.V):
                # check if connected, check if not selected and check if weight is smaller
                if self.graph[u][v] > 0 and visited[v] == False and key[v] > self.graph[u][v]:
                    key[v] = self.graph[u][v]
                    prec[v] = u

        self.printRes(prec)

if __name__ == "__main__":
    print("Prims")
    g = Graph(4,
            [[0, 5, 10, 0],
            [5, 0, 4, 11],
            [10, 4, 0, 5],
            [0, 11, 5, 0]])
    g.prims();
