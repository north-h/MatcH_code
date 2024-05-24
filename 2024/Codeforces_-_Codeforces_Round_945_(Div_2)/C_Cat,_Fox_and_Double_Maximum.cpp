/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-18 12:06:15 ms
 *
 * Problem: C. Cat, Fox and Double Maximum
 * Contest: Codeforces - Codeforces Round 945 (Div. 2)
 * URL:     https://codeforces.com/contest/1973/problem/C
 * MemoryL: 256 MB
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
    int n; cin >> n;
    vector<int> a(n + 1), b, c;
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    auto check = [&](vector<int> t) -> vector<int> {
        vector<int> v1, v2;
        for (int i = 1; i <= n; i ++) {
            if (i & 1) v1.push_back(a[i]);
            else v2.push_back(a[i]);
        }
        v1.push_back(v2.back());
        v2.pop_back();
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<int> ans(n + 1);
        int idx = n;
        for (auto i : v2) {
            ans[mp[i]] = idx --;
        }
        for (auto i : v1) {
            ans[mp[i]] = idx --;
        }
        return ans;
    };
    vector<int> res = check(a);
    int cv = 0;
    for (int i = 2; i < n; i ++) {
        int x = a[i - 1] + res[i - 1];
        int y = a[i] + res[i];
        int z = a[i + 1] + res[i + 1];
        if (y > z && y > x) cv ++;
    }
    if (cv == n / 2 - 1) {
        for (int i = 1; i <= n; i ++) cout << res[i] << ' ';
        cout << '\n';
        return ;
    }
    reverse(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++) {
        mp[a[i]] = i;
    }
    res = check(a);
    reverse(res.begin() + 1, res.end());
    for (int i = 1; i <= n; i ++) cout << res[i] << ' ';
    cout << '\n';
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