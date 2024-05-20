/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-20 22:44:37
 *
 * Problem: C. Beautiful Triple Pairs
 * Contest: Codeforces - Codeforces Round 946 (Div. 3)
 * URL:     https://codeforces.com/contest/1974/problem/C
 * MemoryL: 256 MB
 * TimeL:   4000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    map<pair<int, int>, int> mp1, mp2, mp3;
    map<array<int, 3>, int> mp;
    vector<array<int, 3>> b;
    for (int i = 3; i <= n; i ++) {
        int x = a[i - 2], y = a[i - 1], z = a[i];
        mp1[ {x, y}] ++;
        mp2[ {x, z}] ++;
        mp3[ {y, z}] ++;
        mp[ {x, y, z}] ++;
        b.push_back({x, y, z});
    }
    int ans = 0;
    for (auto [x, y, z] : b) {
        mp1[ {x, y}] --;
        mp2[ {x, z}] --;
        mp3[ {y, z}] --;
        mp[ {x, y, z}] --;
        // cout << x << ' ' << y << ' ' << z << '\n';
        ans += mp1[ {x, y}] + mp2[ {x, z}] + mp3[ {y, z}];
        // cout << mp1[ {x, y}] << ' ' << mp2[ {x, z}] << ' ' << mp3[ {y, z}] << "\n\n";
        ans -= mp[ {x, y, z}] * 3;
    }
    cout << ans << '\n';
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