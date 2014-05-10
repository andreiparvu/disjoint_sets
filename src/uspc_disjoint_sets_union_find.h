#ifndef USPC_DSUF_H
#define USPC_DSUF_H

#include <stdlib.h>

class UnionBySizePathCompressionDisjointSetsUnionFind: public DisjointSetsUnionFind {
  public:
    int *parent, *size;

    UnionBySizePathCompressionDisjointSetsUnionFind(int N): DisjointSetsUnionFind(N) {
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

      int rx = x, nextx;

      while (parent[rx] > 0)
        rx = parent[rx];

      if (x == rx)
        return x;

      while (parent[x] != rx) {
        nextx = parent[x];
        parent[x] = rx;
        x = nextx;
      }

      return rx;
    }

    ~UnionBySizePathCompressionDisjointSetsUnionFind() {
      delete[] parent;
      delete[] size;
    }
};

#endif
