struct DSU {
  vector<int> p;

  void init(int n) {
    p.resize(n);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int x) {
    if (x == p[x])
      return x;
    return p[x] = getp(p[x]);
  }

  bool join(int x, int y) {
    x = getp(x);
    y = getp(y);
    if (x == y) {
      return false;
    }
    p[x] = y;
    return true;
  }
};
