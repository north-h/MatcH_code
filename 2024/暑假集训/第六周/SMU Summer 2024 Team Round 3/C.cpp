// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

#include<bits/stdc++.h>
using namespace std;

int n;

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

void solve() {
    cin >> n;
    DSU dsu(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        if (!dsu.same(i, x)) {
            if (x > n) ans --;
            dsu.merge(i, x);
        }
    }
    set<int> st;
    for (int i = 1; i <= n; i ++) {
        int pi = dsu.find(i);
        if (st.count(pi)) continue;
        ans += dsu.sz[pi];
        st.insert(pi);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}