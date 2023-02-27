#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

vector<vector<int>> graph;

int min_dist(vector<int> dist, vector<bool> visited) {
  int min = INT_MAX, min_index = -1;

  for (int u = 0; u < dist.size(); u++) {
    if (visited[u] == true)
      continue;

    if (min > dist[u]) {
      min = dist[u];
      min_index = u;
    }
  }

  return min_index;
}

void dijkstra() {
  vector<int> dist, prec;
  vector<bool> visited;

  for (int i = 0; i < graph.size(); i++) {
    dist.push_back(INT_MAX);
    prec.push_back(INT_MAX);
    visited.push_back(false);
  }

  dist[0] = 0;

  for (int i = 0; i < graph.size(); i++) {
    int u = min_dist(dist, visited);

    if (u == -1)
      continue;

    visited[u] = true;

    for (int v = 0; v < graph.size(); v++) {
      if (graph[u][v] <= 0 || visited[v])
        continue;

      if (dist[v] > dist[u] + graph[u][v]) {
        dist[v] = dist[u] + graph[u][v];
        prec[v] = u;
      }
    }
  }

  for (int i = 0; i < graph.size(); i++) {
    cout << dist[i] << "\t";
  }
}

int main() {

  graph = {
      {0, 5, 3, 0, 0, 0, 0}, // 0
      {0, 0, 2, 0, 3, 0, 0}, // 1
      {0, 0, 0, 7, 7, 0, 0}, // 2
      {2, 0, 0, 0, 0, 6, 0}, // 3
      {0, 0, 0, 2, 0, 1, 0}, // 4
      {0, 0, 0, 0, 0, 0, 0}, // 5
      {0, 0, 0, 0, 0, 0, 0}  // 6
  };

  dijkstra();

  return 0;
}