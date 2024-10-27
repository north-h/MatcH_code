/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-21 20:56:28
 *
 * Problem: E. Relearn through Review
 * Contest: Codeforces - SMU Autumn 2024 Team Round 8
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/559336/problem/E
 * MemoryL: 1024 MB
 * TimeL:   3000 ms
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
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int ans = 0;
    for (int k = 1; k <= n; k ++) {
        bool ok = true;
        int pv = 1;
        while (pv < n && ok) {
            vector<int> t;
            for (int i = 1; i <= k && pv <= n; i ++) {
                t.push_back(a[pv]);
                pv ++;
            }
            for (int i = 1; i < t.size(); i ++) {
                if (t[i] < t[i - 1]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) ans ++;
    }
    cout << ans << '\n';
    while (q --) {
        ans = 0;
        int p, v; cin >> p >> v;
        a[p] = v;
        // for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
        // cout << '\n';
        for (int k = 1; k <= n; k ++) {
            bool ok = true;
            int pv = 1;
            while (pv < n && ok) {
                vector<int> t;
                for (int i = 1; i <= k && pv <= n; i ++) {
                    t.push_back(a[pv]);
                    pv ++;
                }
                // cout << "t:\n";
                // for (auto i : t) cout << i << ' ';
                // cout << '\n';
                for (int i = 1; i < t.size(); i ++) {
                    if (t[i] < t[i - 1]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans ++;
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}