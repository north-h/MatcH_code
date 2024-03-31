/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-30 22:36:13
 *
 * Problem: C1. Bessie's Birthday Cake (Easy Version)
 * Contest: Codeforces - CodeTON Round 8 (Div. 1 + Div. 2, Rated, Prizes!)
 * URL:     https://codeforces.com/contest/1942/problem/C1
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
// #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x + 1);
    for (int i = 1; i <= x; i ++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int lst = a[1];
    int ans = 0;
    for (int i = 2; i <= x; i ++) {
        if (a[i] - lst == 2 && i == 2) ans ++;
        if (a[i] - lst == 1 && i > 2) ans ++;
        lst = a[i];
    }
    if ((lst + 2) % n == a[1]) ans ++;
    for (int i = 3; i <= x; i ++) {
        if (a[i] - a[i - 1] == 2) ans += 2;
        if (a[i] - a[i - 1] > 2 ) ans ++;        
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