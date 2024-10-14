/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-13 12:35:22
 *
 * Problem: E. Getting Zero
 * Contest: Codeforces - SMU Autumn 2024 Personal Round 4
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/557729/problem/E
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f, M = 32768;

using namespace std;

vector g(M + 1, vector<int>());
vector<int> d(M, -1);
void solve() {
    int n; cin >> n;

    cout << d[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 1; i < M; i ++) {
        g[(i + 1) % M].push_back(i);
        g[i * 2 % M].push_back(i);
    }
    queue<int> q;
    d[0] = 0;
    q.push(0);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (auto i : g[t]) {
            if (d[i] != -1) continue;
            d[i] = d[t] + 1;
            q.push(i);
        }
    }
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}