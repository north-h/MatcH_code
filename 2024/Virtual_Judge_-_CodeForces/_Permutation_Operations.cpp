/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-04 13:47:46 ms
 *
 * Problem:  Permutation Operations
 * Contest: Virtual Judge - CodeForces
 * URL:     https://vjudge.net/problem/CodeForces-1746C#author=GPT_zh
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * =========================================================
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
    vector<ll> a(n + 1);
    set<int> st;
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] = i;
        st.insert(i);
    }
    vector<int> ans(n + 1, -1);
    for (int i = n - 1; i >= 1 && st.size(); i --) {
        while (a[i] > a[i + 1] && st.size()) {
            ll x = a[i] -  a[i + 1];
            auto p = st.lower_bound(x);
            if (p == st.end()) p --;
            a[i + 1] += *p;
            st.erase(*p);
            ans[*p] = i + 1;
        }
    }
    for (int i = n; i >= 1; i --) {
        // if (ans[i] == -1) cout << n << ' ';
        // else cout << ans[i] << ' ';
        cout << mp[i] << ' ';
    }
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