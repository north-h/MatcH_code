/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-09-23 16:00:33
 *
 * Problem: P1168 中位数
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1168
 * MemoryL: 128 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    multiset<int> L, R;
    int mid;
    for (int i = 1; i <= n; i ++) {
        if (L.size()) mid = *L.rbegin();
        if (!L.size() || mid > a[i]) {
            L.insert(a[i]);
        } else {
            R.insert(a[i]);
        }
        while ((int)L.size() - (int)R.size() > 1) {
            auto lt = *L.rbegin();
            R.insert(lt);
            L.erase((--L.end()));
        }
        while ((int)R.size() - (int)L.size() > 0) {
            auto rt = *R.begin();
            L.insert(rt);
            R.erase(R.begin());
        }
        if (i & 1) cout << *L.rbegin() << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}