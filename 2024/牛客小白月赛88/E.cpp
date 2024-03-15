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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    unordered_map<int, int> fa;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        fa[a[i]] = a[i];
    }
    vector<PII> b(m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> b[i].fi >> b[i].se;
    }
    for (int i = m; i >= 1; i --) {
        int x = b[i].fi;
        int y = b[i].se;
        if (fa.count(fa[y])) fa[x] = fa[y];
        else fa[x] = y;
    }
    for (int i = 1; i<= n; i++) cout << fa[a[i]] << " \n"[i == n];
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