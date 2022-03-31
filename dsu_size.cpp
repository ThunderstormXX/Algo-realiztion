struct DSU {
  vector<int> p, sz;

  void init(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
    sz.assign(n, 1);
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
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
    return true;
  }
};
