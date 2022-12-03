#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

map<string, vector<string>> graph;

void depth_first_search(string source,
                        set<string> *visited = new set<string>()) {
  // Print
  cout << source << " ";

  // Node visited
  visited->insert(source);

  // Doesn't have neighbours
  if (!graph.count(source))
    return;

  // Meet neighbours
  for (auto v : graph[source])
    depth_first_search(v, visited); // Recurse
}

void breadth_first_search(string source) {
  set<string> visited = {};

  // Make a queue
  queue<string> queue;
  queue.push(source);

  while (!queue.empty()) {
    string u = queue.front();
    queue.pop();

    cout << u << " ";
    visited.insert(u);

    if (!graph.count(u))
      continue;

    for (string w : graph[u])
      if (!visited.count(w))
        queue.push(w);
  }
}

int main() {
  graph = {
      {"0", {"1", "2"}},
      {"1", {"3"}},
      {"3", {"4", "5"}},
      {"2", {"6", "7"}},
      {"6", {"8", "9"}},
  };

  cout << "Depth First Search : ";
  depth_first_search("0");
  cout << endl;

  cout << "Breadth First Search : ";
  breadth_first_search("0");
  cout << endl;

  return 0;
}