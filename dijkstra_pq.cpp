#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
  int from;
  int to;
  int length;
};

const int INF = INT_MAX / 2;

vector<int> dijkstra(const vector<vector<Edge> >& graph, int start) {
  vector<int> distance(graph.size(), INF);
  distance[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({distance[start], start});
  while (!q.empty()) {
    //q.size()
    int from = q.top().second;
    int cur_distance = q.top().first;
    q.pop();
    if (distance[from] < cur_distance) {
      continue;
    }
    for (auto edge : graph[from]) {  // Elog(q size)
      int to = edge.to;
      if (distance[to] > distance[from] + edge.length) {
        distance[to] = distance[from] + edge.length;
        q.push({distance[to], to});
      }
    }
  }
  return distance;
}

int main() {
  vector<vector<Edge> > graph;
  int number_vertices;
  int number_edges;

  cin >> number_vertices >> number_edges;
  graph.resize(number_vertices);
  for (int i = 0; i < number_edges; ++i) {
    int from, to, length;
    cin >> from >> to >> length;
    graph[from].push_back({from, to, length});
    graph[to].push_back({to, from, length});  // if undirected graph
  }

  vector<int> distance = dijkstra(graph, 0);
  for (int i = 0; i < distance.size(); ++i) {
    cout << i << ' ' << distance[i] << '\n';
  }

  return 0;
}
