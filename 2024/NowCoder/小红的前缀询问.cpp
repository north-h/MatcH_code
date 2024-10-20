/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 19:16:58
 *
 * Problem: 小红的前缀询问
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/92662/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        a[i] = x;
        mp[x].push_back(i);
    }
    // for (auto &[x, y] : mp) reverse(y.begin(), y.end());
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        if (mp[a[i]].size() == 1) s[i] += s[i - 1];
        else {
            auto p = lower_bound(mp[a[i]].begin(), mp[a[i]].end(), i) - mp[a[i]].begin();
            s[i] = p;
            s[i] += s[i - 1];
        }
    }
    for (int i = 1; i <= n; i ++) cout << s[i] << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}