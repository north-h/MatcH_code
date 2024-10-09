/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-09 20:23:50
 *
 * Problem: P1297 [国家集训队] 单选错位
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P1297
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 10000010, INF = 0x3f3f3f3f;

using namespace std;

int a[N];

void solve() {
    int n, A, B, C;
    cin >> n >> A >> B >> C >> a[1];
    for (int i = 2; i <= n; i++)
        a[i] = (a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % C + 1;
    double ans = 0;
    for (int i = 1; i < n; i ++) {
        ans += 1.0 / max(a[i], a[i + 1]);
    }
    ans += 1.0 / max(a[1], a[n]);
    cout << fixed << setprecision(3) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}