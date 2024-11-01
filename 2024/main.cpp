/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-11-01 22:59:44
 *
 * Problem: C. Trinity
 * Contest: Codeforces - Codeforces Round 983 (Div. 2)
 * URL:     https://codeforces.com/contest/2032/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
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
    sort(a.begin() + 1, a.end());
    int mx = a[n];
    int ans = 0, res = 0;
    for (int i = n - 1; i >= 1; i --) {
        if ((a[i] + a[i + 1]) <= a[n]) {
            ans = i;
            break;
        }
    }
    for (int i = n; i >= 1; i --) {
        if ((a[1] + a[2]) > a[i]) {
            ans = min(ans, n - i);
            break;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}