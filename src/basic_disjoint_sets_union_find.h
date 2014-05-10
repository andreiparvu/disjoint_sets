#ifndef BASIC_DSUF_H
#define BASIC_DSUF_H

#include <stdlib.h>

class BasicDisjointSetsUnionFind: public DisjointSetsUnionFind {
  public:
    int *parent;

    BasicDisjointSetsUnionFind(int N): DisjointSetsUnionFind(N) {
      parent = new int[N + 1];
      for (int i = 1; i <= N; i++) {
        parent[i] = 0;
      }
    }

    void Union(int x, int y) {
      if (x <= 0 || x > N || y <= 0 || y > N)
        return;
      int rx = Find(x), ry = Find(y);
      if (rx != ry) {
        parent[rx] = ry;
      }
    }

    int Find(int x) {
      if (x <= 0 || x > N)
        return 0;
      while (parent[x] > 0)
        x = parent[x];
      return x;
    }

    ~BasicDisjointSetsUnionFind() {
      delete[] parent;
    }
};

#endif
