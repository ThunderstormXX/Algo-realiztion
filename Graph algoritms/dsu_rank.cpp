struct DSU {
  vector<int> p, rank;

  void init(int n) {
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
