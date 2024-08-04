/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-04 22:35:52
 *
 * Problem: C. Light Switches
 * Contest: Codeforces - Codeforces Round 963 (Div. 2)
 * URL:     https://codeforces.com/contest/1993/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    if (k == 1 && mp.size() != 1) {
        cout << -1 << '\n';
        return ;
    }
    sort(a.begin() + 1, a.end());
    int l = a[n], r = a[n] + k - 1;
    vector<array<int, 2>> seg;
    for (int i = 1; i < n; i ++) {
        int lt1 = a[i] + (l - a[i] + 2 * k - 1) / (2 * k) * (2 * k);
        int rt1 = lt1 + k - 1;
        int lt2 = a[i] + (l - a[i]) / (2 * k) * (2 * k);
        int rt2 = lt2 + k - 1;
        int r1 = min(rt1, r) - max(lt1, l);
        int r2 = min(rt2, r) - max(lt2, l);
        if (r1 >= r2) seg.push_back({lt1, rt1});
        else seg.push_back({lt2, rt2});
    }
    for (int i = 0; i < seg.size(); i ++) {
        auto [lt, rt] = seg[i];
        l = max(l, lt);
        r = min(r, rt);
    }
    if (l > r) cout << -1 << '\n';
    else cout << l << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}