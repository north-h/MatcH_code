/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-25 20:00:21 ms
 *
 * Problem: C - Bingo 2
 * Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
 * URL:     https://atcoder.jp/contests/abc355/tasks/abc355_c
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
    int N, T; cin >> N >> T;
    vector<int> A(T + 1);
    vector<vector<int>> h(N + 10), l(N + 10);
    vector<int> dg, udg;
    for (int i = 1; i <= T; i ++) {
        cin >> A[i];
        A[i] --;
        int x = A[i] / N, y = A[i] % N;
        if (x == y) dg.push_back(A[i]);
        if (x + y == N - 1) udg.push_back(A[i]);
        h[x].push_back(A[i]);
        l[y].push_back(A[i]);
        if (dg.size() == N || udg.size() == N || h[x].size() == N || l[y].size() == N) {
            cout << i << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
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