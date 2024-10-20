/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 13:21:52
 *
 * Problem: 市场
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/93674/I
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
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
    int n, mx = 0; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i], mx = max(mx, a[i]);
    int ans = 0, lst = 0;
    for (int j = 1; j <= n; j ++) {
        ans += abs(lst - a[j]);
        lst = a[j];
    }
    auto b = a;
    sort(b.begin() + 1, b.end());
    ans += abs(a[n]);
    // cout << ans << '\n';
    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            cout << ans - abs(a[i]) - abs(a[i] - a[i + 1]) + abs(a[i + 1]) << ' ';
        } else if (i == n) {
            cout << ans - abs(a[i - 1] - a[i]) - abs(a[i]) + abs(a[i - 1]) << ' ';
        }
        else cout << ans + abs(a[i - 1] - a[i + 1]) - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) << ' ';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}