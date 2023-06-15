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

vector<int> ford_bellman(const vector<Edge>& edges, int number_vertices, int start) {
  vector<int> distance(number_vertices, INF);
  distance[start] = 0;
  for (int iter = 0; iter < number_vertices - 1; ++iter) {
    for (auto edge : edges) {
      if (distance[edge.from] < INF &&
          distance[edge.to] > distance[edge.from] + edge.length) {
        distance[edge.to] = distance[edge.from] + edge.length;
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

  vector<int> distance = ford_bellman(edges, number_vertices, 0);
  for (int i = 0; i < distance.size(); ++i) {
    cout << i << ' ' << distance[i] << '\n';
  }

  return 0;
}
