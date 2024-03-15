// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 1001000;
const int INF = 0x3f3f3f3f;

using namespace std;

struct DSU {
    vector<int> fa;
 
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        // for (int i = 1; i <= n; i ++) fa[i] = i;
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
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(N);
    vector<int> a(n + 1);
    // for (auto i : a) cout << i << ' ';
    for (int i = 1; i <= n; i ++) cin >> a[i];
    vector<PII> b(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> b[i].fi >> b[i].se;
        dsu.merge(b[i].fi, b[i].se);
    }
    // for (int i = 1; i <= n; i ++) cout << dsu.find(i) << " \n"[i == n];
    // debug1(dsu.same(1, 2));
    // debug2(dsu.find(1), dsu.find(2));
    set<int> st;
    for (int i = m; i >= 1; i --) {
        if (st.count(dsu.find(b[i].se))) continue;
        st.insert(dsu.find(b[i].fi));
        st.insert(dsu.find(b[i].se));
        for (int j = 1; j <= n; j ++) {
            if (dsu.same(a[j], b[i].se)) {
                // debug2(b[i].fi, b[i].se);
                a[j] = b[i].se; 
            }
        }
    }
    
    for (int i = 1; i<= n; i++) cout << a[i] << " \n"[i == n];
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}