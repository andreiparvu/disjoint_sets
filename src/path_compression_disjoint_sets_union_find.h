#ifndef PC_DSUF_H
#define PC_DSUF_H

#include <stdlib.h>

class PathCompressionDisjointSetsUnionFind: public DisjointSetsUnionFind {
  public:
    int *parent;

    PathCompressionDisjointSetsUnionFind(int N): DisjointSetsUnionFind(N) {
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

      int rx = x, nextx;

      while (parent[rx] > 0) {
        rx = parent[rx];
      }

      if (x == rx)
        return x;

      while (parent[x] != rx) {
        nextx = parent[x];
        parent[x] = rx;
        x = nextx;
      }

      return rx;
    }

    ~PathCompressionDisjointSetsUnionFind() {
      delete[] parent;
    }
};

#endif
