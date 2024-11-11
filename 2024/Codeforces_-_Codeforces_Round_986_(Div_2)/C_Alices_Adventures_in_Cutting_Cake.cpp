/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-11 18:30:01
 *
 * Problem: C. Alice's Adventures in Cutting Cake
 * Contest: Codeforces - Codeforces Round 986 (Div. 2)
 * URL:     https://codeforces.com/contest/2028/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m, v; cin >> n >> m >> v;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int cv = 0;
    vector<int> tp;
    tp.push_back(0);
    for (int i = 1; i <= n; i ++) {
        if (cv + a[i] < v) cv += a[i];
        else tp.push_back(i), cv = 0;
        if (tp.size() == m + 1) break;
    }
    if (tp.size() < m + 1) {
        cout << -1 << '\n';
        return ;
    }
    int ans = s[n] - s[tp.back()];
    cv = 0;
    tp.pop_back();
    for (int i = n; i >= 1; i --) {
        if (cv + a[i] < v) cv += a[i];
        else if (tp.size() && tp.back() < i) {
            ans = max(ans, s[i - 1] - s[tp.back()]);
            tp.pop_back();
            cv = 0;
        }
        else break;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}