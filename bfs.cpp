#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
  int from;
  int to;
};

const int INF = INT_MAX / 2;

vector<int> bfs(const vector<vector<Edge> >& graph, int start) {
  vector<int> distance(graph.size(), INF);
  distance[start] = 0;
  queue<int> q;  // вершины лежат в порядке увеличения расстояния, каждая вершина побывает в очереди один раз, в момент когда кладем вершину в очередь расстояние посчитано верно
  q.push(start); // start,a,b..
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    for (auto edge : graph[from]) {
      int to = edge.to;
      if (distance[to] > distance[from] + 1) {
        distance[to] = distance[from] + 1;
        q.push(to);
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
    int from, to;
    cin >> from >> to;
    graph[from].push_back({from, to});
    graph[to].push_back({to, from});  // if undirected graph
  }

  vector<int> distance = bfs(graph, 0);
  for (int i = 0; i < distance.size(); ++i) {
    cout << i << ' ' << distance[i] << '\n';
  }

  return 0;
}
