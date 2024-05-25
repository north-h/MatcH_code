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
        if (i % 2 == 0) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    b.pop_back();
    sort(b.begin(), b.end());
    reverse(c.begin(), c.end());
    c.pop_back();
    reverse(c.begin(), c.end());
    sort(c.begin(), c.end());
    // for (auto i : b) cout << i << ' '; cout << '\n';
    // for (auto i : c) cout << i << ' '; cout << '\n';
    auto check = [&](vector<int> t) {
        vector<int> ans(n + 1);
        set<int> st;
        for (int i = 1; i <= n; i ++) st.insert(i);
        for (int i = 0, j = n; i < t.size(); i ++, j --) {
            ans [mp[t[i]]] = j;
            st.erase(j);
        }
        vector<array<int, 2>> T;
        for (int i = 0; i < t.size(); i ++) {
            int id = mp[t[i]];
            if (i == 0) {
                T.push_back({a[id] + ans[id] - a[id - 1], id - 1});
            } else if (i == t.size() - 1) {
                T.push_back({a[id] + ans[id] - a[id] + 1, id + 1});
            } else {
                int ap = mp[t[i - 1]], bp = mp[t[i]];
                T.push_back({min(a[ap] + ans[ap] - a[ap + 1], a[bp] + ans[bp] - a[bp - 1]), ap + 1});
            }
        }
        return ans;
    };
    vector<int> res(n + 1);
    res = check(b);
    int v = 0, vc = 0;
    vc += !res[1];
    vc += !res[n];
    for (int i = 2; i < n; i ++) {
        int x = res[i] + a[i];
        int y = res[i + 1] + a[i + 1];
        int z = res[i - 1] + a[i - 1];
        if (x > y && x > z) v ++;
        vc += !res[i];
    }
    for (int i = 1; i <= n; i ++) cout << res[i] << " \n"[i == n];
    if (v == n / 2 - 1 && !vc) {
        for (int i = 1; i <= n; i ++) cout << res[i] << " \n"[i == n];
        return ;
    }
    // cout << '-' << '\n';
    res = check(c);
    for (int i = 1; i <= n; i ++) cout << res[i] << " \n"[i == n];
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