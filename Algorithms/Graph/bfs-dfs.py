class Graph:

    def __init__(self):
        self.graph = dict()

    def addEdge(self, u, v):
        # self.graph[u] = []
        if u not in self.graph.keys():
            self.graph[u] = []

        self.graph[u].append(v)

    def bfs(self, start):
        q = []  # Create queue
        visited = set()

        if start not in self.graph.keys():
            print(start, "does not exist")
            return

        q.append(start) # Add start node to queue
        visited.add(start)

        print(start, end=" ")

        while len(q) > 0:
            # Remove vertex from queue, whose neighbour will be visited now
            v = q.pop(0)

            for w in self.graph[v]:
                if w not in visited:
                    print(w, end=" ")

                    q.append(w) # Add further nodes to visit
                    visited.add(w)
        
        print()

    def dfs(self, start):
        s = [] # Create stack

        visited = set()

        if  start not in self.graph.keys():
            print(start, "does not exist")
            return
        
        s.append(start)


        while len(s) > 0:
            v = s.pop()
            visited.add(start)

            print(v, end=" ")

            for w in self.graph[v]:

                if w not in visited:
                    s.append(w)
                    visited.add(w)

        print()

    def dfs_recursive(self, node, visited=set()):
        visited.add(node)
        print(node)

        if node not in self.graph.keys():
            print(node, "does not exist")
            return

        for w in self.graph[node]:
            if w not in visited:
                self.dfs_recursive(w, visited)


    def print(self):
        for [u, v] in self.graph.items():
            print(u, "->", v)


if __name__ == '__main__':
    g = Graph()
    # g.addEdge(0, 1)
    # g.addEdge(0, 2)
    # g.addEdge(1, 2)
    # g.addEdge(2, 0)
    # g.addEdge(2, 3)
    # g.addEdge(3, 3)

    # g.addEdge(0, 1)
    # g.addEdge(0, 2)
    # g.addEdge(1, 0)
    # g.addEdge(1, 3)
    # g.addEdge(1, 4)
    # g.addEdge(2, 0)
    # g.addEdge(3, 1)
    # g.addEdge(4, 2)
    # g.addEdge(4, 3)

    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 2)
    g.addEdge(2, 3)
    g.addEdge(3, 1)
    g.addEdge(3, 2)

    print("\nBreadth First Search")
    g.bfs(0)

    print("\nDepth First Search")
    g.dfs(0)

    print("\nDepth First Search")
    g.dfs_recursive(0)

    print("\nGraph")
    g.print()