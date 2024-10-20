/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 19:46:09
 *
 * Problem: 小红和小紫的博弈游戏
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/92662/D
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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 0;
    ans += min(a, b) + min(c, d);
    if (a > b) {
        if (c > d) ans += min(max(a, b) - min(a, b), max(c, d) - min(c, d));
    } else {
        if (c < d) ans += min(max(a, b) - min(a, b), max(c, d) - min(c, d));
    }
    // debug1(ans);
    if (ans & 1) cout << "kou\n";
    else cout << "yukari\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}