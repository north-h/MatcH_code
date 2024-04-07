/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-07 00:19:50
 *
 * Problem: C. Ticket Hoarding
 * Contest: Codeforces - Codeforces Global Round 25
 * URL:     https://codeforces.com/contest/1951/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b;
    unordered_map<int, int> t;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int x = k / m, y = k % m, nm = x + (y != 0);
    b = a;
    sort(b.begin(), b.end());
    for (int i = 1; i <= nm; i ++) t[b[i]] ++;
    vector<int> T;
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        if (t[a[i]] > 0 && T.size() < nm) {
            T.push_back(a[i]);
            t[a[i]] --;
            mx  =max(mx, a[i]);
        }
    }
    ll ans = 0, c = 0;
    for (int i = 0; i < T.size(); i ++) {
        if (T[i] == mx && y != 0) {
            ans += (ll)(T[i] + c) * y ;
            c += y;
            y = 0;
        } else {
            ans += (ll)(T[i] + c) * m;
            c += m;
        }
    }
    cout << ans << endl;
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