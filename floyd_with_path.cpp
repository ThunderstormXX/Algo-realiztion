#include <vector>
#include <iostream>
#include <climits>
using namespace std;

struct Edge {
  int from;
  int to;
  int length;
};

const int INF = INT_MAX / 2;

vector<int> get_path(int u, int v, const vector<vector<int>>& path) {
  if (path[u][v] == 0) {
    return {u, v};
  }
  int mid = path[u][v];
  vector<int> p1 = get_path(u, mid);
  vector<int> p2 = get_path(mid, v);
  for (int i = 1; i < p2.size(); ++i) {
    p1.push_back(p2[i]);
  }
  return p1;
}

vector<vector<int>> floyd(const vector<Edge>& edges, int number_vertices) {
  vector<vector<int>> distance(number_vertices,
                               vector<int>(number_vertices, INF));
  vector<vector<int>> path(number_vertices,
                           vector<int>(number_vertices, INF));
  for (int i = 0; i < number_vertices; ++i) distance[i][i] = 0;
  for (auto edge : edges) {
    distance[edge.from][edge.to] =
        min(distance[edge.from][edge.to], edge.length);
    path[edge.from][edge.to] = 0;
  }
  for (int mid = 0; mid < number_vertices; ++mid) {
    for (int from = 0; from < number_vertices; ++from) {
      for (int to = 0; to < number_vertices; ++to) {
        if (distance[from][mid] < INF && distance[mid][to] < INF) {
          auto cand_distance = distance[from][mid] + distance[mid][to];
          if (distance[from][to] > cand_distance) {
            distance[from][to] = cand_distance;
            path[from][to] = mid;
          }
        }
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
