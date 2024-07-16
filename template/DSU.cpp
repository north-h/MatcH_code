struct DSU {
    vector<int> fa, sz;
 
    DSU(int n) {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        iota(fa.begin(), fa.end(), 0);
    }
 
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
 
    bool same(int x, int y) {
        int px = find(x);
        int py = find(y);
        return px == py;
    }
 
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            fa[px] = py;
            sz[py] += sz[px];
        }
    }
};