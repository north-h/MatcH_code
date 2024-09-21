/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-09-21 23:04:40
 *
 * Problem: C. Robin Hood in Town
 * Contest: Codeforces - Codeforces Round 974 (Div. 3)
 * URL:     https://codeforces.com/contest/2014/problem/C
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
    int mx = 0, p = 0, sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            p = i;
        }
        sum += a[i];
    }
    // debug2(mx, p);
    if (n == 1) {
        cout << -1 << '\n';
        return ;
    }
    auto check = [&](int x) -> bool {
        a[p] += x;
        int res = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i] * n * 2 < (sum + x)) res ++;
        }
        a[p] -= x;
        if (res > n / 2) return true;
        return false;
    };
    int l = 0, r = 1e15, ans = -1;
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