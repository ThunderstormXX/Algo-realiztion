#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
  int from;
  int to;
  int length;
  Edge(int from, int to, int length): from(from), to(to), length(length) {}
};

struct DSU {
  vector<int> p, rank;

  DSU(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
    rank.assign(n, 0);
  }

  int getp(int x) {
    if (x == p[x]) {
      return x;
    }
    return p[x] = getp(p[x]);
  }

  bool join(int x, int y) {
    x = getp(x);
    y = getp(y);
    if (x == y) {
      return false;
    }
    if (rank[x] > rank[y]) {
      swap(x, y);
    }
    p[x] = y;
    if (rank[x] == rank[y]) {
      ++rank[y];
    }
    return true;
  }
};

vector<Edge> kraskal(vector<Edge> edges, int number_vertices) {
  DSU dsu(number_vertices);
  sort(edges.begin(), edges.end(), [&](auto a, auto b){ return a.length < b.length; });
  vector<Edge> min_spanning_tree;
  for (auto e : edges) {
    if (dsu.join(e.from, e.to)) {
      min_spanning_tree.push_back(e);
    }
  }
  return min_spanning_tree;
}

int main() {
  vector<Edge> edges;
  int number_vertices;
  int number_edges;

  cin >> number_vertices >> number_edges;
  for (int i = 0; i < number_edges; ++i) {
    int from, to, length;
    cin >> from >> to >> length;
    edges.emplace_back(from, to, length);
  }

  vector<Edge> min_spanning_tree = kraskal(edges, number_vertices);
  long long sum = 0;
  for (auto e : min_spanning_tree) {
    sum += e.length;
  }

  cout << sum << endl;

  return 0;
}
