#include <vector>
#include <iostream>
#include <climits>
using namespace std;

struct Edge {
  int from;
  int to;
  int length;
};

const int INF = INT_MAX / 2 - 1;

vector<vector<int>> floyd(const vector<Edge>& edges, int number_vertices) {
  vector<vector<int>> distance(number_vertices,
                               vector<int>(number_vertices, INF));
  for (int i = 0; i < number_vertices; ++i) distance[i][i] = 0;
  for (auto edge : edges) {
    distance[edge.from][edge.to] =
        min(distance[edge.from][edge.to], edge.length);
  }
  for (int mid = 0; mid < number_vertices; ++mid) {
    for (int from = 0; from < number_vertices; ++from) {
      for (int to = 0; to < number_vertices; ++to) {
        distance[from][to] = std::min(distance[from][to], distance[from][mid] + distance[mid][to]);
      }
    }
  }
  return distance;
}

int main() {
  vector<Edge> edges;
  int number_vertices;
  int number_edges;

  cin >> number_vertices >> number_edges;
  for (int i = 0; i < number_edges; ++i) {
    int from, to, length;
    cin >> from >> to >> length;
    edges.push_back({from, to, length});
    edges.push_back({to, from, length});  // if undirected graph
  }

  vector<vector<int>> distance = floyd(edges, number_vertices);
  for (int i = 0; i < number_vertices; ++i) {
    for (int j = 0; j < number_vertices; ++j) {
      cout << distance[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
