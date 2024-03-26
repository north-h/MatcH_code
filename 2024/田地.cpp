// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct DSU {
    vector<int> fa;

    DSU(int n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i ++) fa[i] = i;
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
    int n, m, k;
    cin >> n >> m >> k;
    DSU d1(n + 1);
    map<PII, int> p2;
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            d1.merge(a, b);
        } else {
            p2[{a, b}] ++;
            p2[{b, a}] ++;
        }
    }
    while (k --) {
        int a, b;
        cin >> a >> b;
        bool f1 = d1.same(a, b);
       if (p2.count({a, b}) && !f1) cout << "No way" << endl;
       else if (!p2.count({a, b}) && f1) cout << "No problem" << endl;
       else if (!p2.count({a, b}) && !f1) cout << "OK" << endl;
       else cout << "OK but..." << endl;
    }
}


int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}