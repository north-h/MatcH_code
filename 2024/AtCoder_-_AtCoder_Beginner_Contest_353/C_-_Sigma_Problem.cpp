/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-11 20:00:21 ms
 *
 * Problem: C - Sigma Problem
 * Contest: AtCoder - AtCoder Beginner Contest 353
 * URL:     https://atcoder.jp/contests/abc353/tasks/abc353_c
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int mod = 1e8;


using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int sum = 0;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1 ; i <= n; i ++) s[i] = s[i - 1] + a[i];
    for (int i = n; i >= 2; i --) {
        int l = 1, r = i - 1, res = i, x = mod - a[i];
        while (l <= r) {
            int mid = l + r >> 1;
            if (a[mid] >= x) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        sum += (s[res - 1] + a[i] * (res - 1));
        sum += (s[i - 1] - s[res - 1]) + (a[i] - mod) * (i - res);
    }
    cout << sum << '\n';
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