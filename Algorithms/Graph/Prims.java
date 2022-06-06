import java.util.Arrays;

public class Prims {

    public int graph[][];
    private String nodeNames[];

    Prims(int[][] init_graph, String[] nodeNames) {
        this.graph = init_graph;
        this.nodeNames = nodeNames;
    }

    String getNodeName(int index) {
        return nodeNames[index];
    }

    void prims(int src) {
        boolean selected[] = new boolean[this.graph.length];
        int noEdge = 0;

        Arrays.fill(selected, false);
        selected[0] = true;

        System.out.println("Edge\t\tWeight");

        while (noEdge < graph.length - 1) {
            int min = Integer.MAX_VALUE, x = 0, y = 0;

            for (int i = 0; i < graph.length; i++) {
                if (selected[i]) {
                    for (int j = 0; j < graph.length; j++) {
                        if (!selected[j] && graph[i][j] != 0) {
                            if (min > graph[i][j]) {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            System.out.println(x + " <-> " + y + "\t\t" + graph[x][y]);
            selected[y] = true;
            noEdge++;
        }
    }

    public static void main(String[] args) {
        int graph[][] = {
                { 0, 9, 75, 0, 0 },
                { 9, 0, 95, 19, 42 },
                { 75, 95, 0, 51, 66 },
                { 0, 19, 51, 0, 31 },
                { 0, 42, 66, 31, 0 }
        };

        Prims p = new Prims(graph,
                new String[] { "A", "B", "C", "D", "E" });

        p.prims(0);

    }

}
