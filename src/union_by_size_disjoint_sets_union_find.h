#ifndef USIZE_DSUF_H
#define USIZE_DSUF_H

#include <stdlib.h>

class UnionBySizeDisjointSetsUnionFind: public DisjointSetsUnionFind {
  public:
    int *parent, *size;

    UnionBySizeDisjointSetsUnionFind(int N): DisjointSetsUnionFind(N) {
      parent = new int[N + 1];
      size = new int[N + 1];
      for (int i = 1; i <= N; i++) {
        parent[i] = 0;
        size[i] = 1;
      }
    }

    void Union(int x, int y) {
      if (x <= 0 || x > N || y <= 0 || y > N)
        return;
      int rx = Find(x), ry = Find(y);
      if (rx != ry) {
        if (size[ry] >= size[rx]) {
          parent[rx] = ry;
          size[ry] += size[rx];
        } else {
          parent[ry] = rx;
          size[rx] += size[ry];
        }
      }
    }

    int Find(int x) {
      if (x <= 0 || x > N)
        return 0;
      while (parent[x] > 0)
        x = parent[x];
      return x;
    }

    ~UnionBySizeDisjointSetsUnionFind() {
      delete[] parent;
      delete[] size;
    }
};

#endif
