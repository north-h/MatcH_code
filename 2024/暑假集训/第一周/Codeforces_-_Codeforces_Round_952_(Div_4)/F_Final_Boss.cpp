/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-07 14:26:01 ms
 *
 * Problem: F. Final Boss
 * Contest: Codeforces - Codeforces Round 952 (Div. 4)
 * URL:     https://codeforces.com/contest/1985/problem/F
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
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
    int h, n; cin >> h >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    auto check = [&](int x) -> bool {
        __int128 res = 0;
        for (int i = 1; i <= n; i ++) {
            res += (__int128)(x + b[i] - 1) / b[i] * a[i];
            if (res >= h) return true;
        }
        return false;
    };
    int l = 0, r = 1e14, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
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