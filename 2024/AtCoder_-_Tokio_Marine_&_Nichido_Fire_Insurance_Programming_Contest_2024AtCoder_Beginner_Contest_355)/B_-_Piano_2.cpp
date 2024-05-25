/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 20:00:17 ms
 *
 * Problem: B - Piano 2
 * Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
 * URL:     https://atcoder.jp/contests/abc355/tasks/abc355_b
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    map<int, int> A, B;
    vector<int> C;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        A[x] = i;
        C.push_back(x);
    }
    for (int i = 1; i <= m; i ++) {
        int x; cin >> x;
        B[x] = i;
        C.push_back(x);
    }
    sort(C.begin(), C.end());
    for (int i = 1; i < C.size(); i ++) {
        if (A.count(C[i]) && A.count(C[i - 1])) {
            cout << "Yes" << '\n';
            return ;
        }
    }
    cout << "No" << '\n';
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