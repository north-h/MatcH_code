/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:06 ms
 *
 * Problem: B3913 [语言月赛 202401] 装满葡萄汁的酒杯
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/B3913?contestId=165469
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
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
    int n;
    cin >> n;
    if (n <= 100) cout << 100 << endl;
    else if (n > 100 && n <= 150) cout << 150 << endl;
    else if (n > 150 && n <= 300) cout << 300 << endl;
    else if (n > 300 && n <= 400) cout << 400 << endl;
    else if (n > 1000) cout << 1000 << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}