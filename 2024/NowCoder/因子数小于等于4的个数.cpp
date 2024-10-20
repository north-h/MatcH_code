/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 14:16:31
 *
 * Problem: 因子数小于等于4的个数
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/93674/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 40, INF = 0x3f3f3f3f;

using namespace std;

int vis[N], pre[N];

void solve() {
    int l, r; cin >> l >> r;
    cout << pre[r] - pre[l - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 2; i < N; i ++) {
        if (vis[i]) continue;
        for (int j = i + i; j < N; j += i) {
            vis[j] = 1;
        }
    }
    vector<int> p;
    vis[0] = vis[1] = 1;
    for (int i = 1; i < N; i ++) {
        if (!vis[i]) p.push_back(i);
    }
    for (int i = 1; i < N; i ++) {
        int x = i, sum = 1, ok = 1;
        if (!vis[i]) {
            pre[i] = 1;
            continue;
        }
        for (auto j : p) {
            int cnt = 0;
            if (j > i) break;
            if (x % j == 0) {
                while (x % j == 0) x /= j, cnt ++;
                sum *= (cnt + 1);
                if (sum > 4) {
                    ok = 0;
                    break;
                }
            }
            if (!vis[x]) break;
        }
        if (x > 1) sum *= 2;
        if (sum > 4) ok = 0;
        if (ok) pre[i] = 1;
    }
    // for (int i = 1; i < N; i ++) cout << pre[i] << ' ';
    // cout << '\n';
    for (int i = 1; i < N; i ++) pre[i] += pre[i - 1];
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}