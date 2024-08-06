/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-06 22:39:42
 *
 * Problem: E. Triple Operations
 * Contest: Codeforces - Codeforces Round 964 (Div. 4)
 * URL:     https://codeforces.com/contest/1999/problem/E
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 200010;
const int INF = 0x3f3f3f3f;

using namespace std;

int get(int x) {
    int cnt = 0;
    while (x) {
        cnt ++;
        x /= 3;
    }
    return cnt;
}

int s[N];

void solve() {
    int l, r; cin >> l >> r;
    int ans = 0, pos;
    if (l == 1) ans += 3, pos = 3;
    else {
        int x = get(l);
        int r = l + 1;
        for (int i = 1; i <= x; i ++) r *= 3;
        int y = get(r);
        ans += x + y;
        pos = l + 2;
    }
    ans += s[r] - s[pos - 1];
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    for (int i = 1; i < N; i ++) {
        s[i] = get(i);
        s[i] += s[i - 1];
    }
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}