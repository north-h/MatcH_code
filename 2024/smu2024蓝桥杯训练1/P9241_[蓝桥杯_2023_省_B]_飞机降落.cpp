/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:18 ms
 *
 * Problem: P9241 [蓝桥杯 2023 省 B] 飞机降落
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P9241?contestId=165469
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * =========================================================
 */

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
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

struct edge{int T, D, L;};

void solve() {
    int n;
    cin >> n;
    map<int, edge> mp;
    for (int i = 1; i <= n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        mp[i] = {x, y, z};
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i ++) b[i] = i;
    do {
        int tm = 0;
        bool f = true;
        for (int i = 1; i <= n; i ++) {
            int d = b[i];
            int t = mp[d].T + mp[d].D;
            if (tm <= t) {
                tm = max(tm, mp[d].T) + mp[d].L;
            } else {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
            return ;
        }
    }while (next_permutation(b.begin() + 1, b.end()));
    cout << "NO" << endl;
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