#ifndef DSUF_H
#define DSUF_H

class DisjointSetsUnionFind {
  public:
    int N;

    DisjointSetsUnionFind(int N) {
      this->N = N;
    }

    virtual void Union(int x, int y) = 0;
    virtual int Find(int x) = 0;
};

#endif
