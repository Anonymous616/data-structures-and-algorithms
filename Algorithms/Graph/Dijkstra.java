public class Dijkstra {

    public int graph[][];
    private String nodeNames[];

    Dijkstra(int[][] init_graph, String[] nodeNames) {
        this.graph = init_graph;
        this.nodeNames = nodeNames;
    }

    String getNodeName(int index) {
        return nodeNames[index];
    }

    int minDist(int dist[], boolean unvisited[]) {
        int minVal = Integer.MAX_VALUE, minNode = 0;

        for (int i = 0; i < graph.length; i++) {
            // Check if node was visited and
            // its distance is better than the minimum value
            if (!unvisited[i] && dist[i] <= minVal) {
                minVal = dist[i];
                minNode = i;
            }
        }

        return minNode;
    }

    void dijkstra(int src) {
        int parent[] = new int[graph.length];
        int dist[] = new int[graph.length];
        boolean unvisited[] = new boolean[graph.length];

        // Initializing distance and unvisited
        for (int i = 0; i < graph.length; i++) {
            dist[i] = Integer.MAX_VALUE;
            unvisited[i] = false;
        }

        dist[src] = 0;
        parent[src] = -1;

        for (int i = 0; i < graph.length; i++) {

            int u = minDist(dist, unvisited);

            unvisited[u] = true;

            for (int v = 0; v < graph.length; v++) {

                // If dest node was visited previously then skip
                if (unvisited[v])
                    continue;

                // If graph edge is 0 means theres no edge
                if (graph[u][v] == 0)
                    continue;

                // Check if new distance is better
                if (dist[v] > dist[u] + graph[u][v]) {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
            }

        }

        displayDijkstra(dist, parent);
    }

    void displayDijkstra(int dist[], int parent[]) {

        System.out.println("Vertex\t\tDistance\tPath");
        for (int i = 0; i < graph.length; i++) {
            int parentNode = parent[i];

            // For nodes that don't have any route
            if (dist[i] == Integer.MAX_VALUE) {
                System.out.println(getNodeName(i) + "\t\t" + "∞ (INF)"
                        + "\t\t" + "None");
                continue;
            }

            System.out.print(getNodeName(i) + "\t\t" + dist[i]
                    + "\t\t" + getNodeName(i));

            // Traverse till we find the last parent node (i.e. Node 0)
            while (parentNode != -1) {
                System.out.print(" <- " + getNodeName(parentNode));
                parentNode = parent[parentNode];
            }

            System.out.println();
        }
    }

    public static void main(String[] args) {
        int graph[][] = {
                // 0 1 2 3 4 5 6
                { 0, 5, 3, 0, 0, 0, 0 }, // 0
                { 0, 0, 2, 0, 3, 0, 0 }, // 1
                { 0, 0, 0, 7, 7, 0, 0 }, // 2
                { 2, 0, 0, 0, 0, 6, 0 }, // 3
                { 0, 0, 0, 2, 0, 1, 0 }, // 4
                { 0, 0, 0, 0, 0, 0, 0 }, // 5
                { 0, 0, 0, 0, 0, 0, 0 } // 6
        };

        Dijkstra d = new Dijkstra(graph,
                new String[] { "A", "B", "C", "D", "E", "F", "G", "H" });

        d.dijkstra(0);

    }

}
