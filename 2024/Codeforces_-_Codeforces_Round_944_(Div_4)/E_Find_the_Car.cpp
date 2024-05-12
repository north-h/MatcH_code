/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-11 13:31:44
 *
 * Problem: E. Find the Car
 * Contest: Codeforces - Codeforces Round 944 (Div. 4)
 * URL:     https://codeforces.com/contest/1971/problem/E
 * MemoryL: 256 MB
 * TimeL:   3000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define PII pair<int, int>
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i ++) cin >> a[i];
    for (int i = 1; i <= k; i ++) cin >> b[i];
    while (q --) {
        int x; cin >> x;
        if (x == 0) { cout << 0 << ' '; continue; }
        int l = 1, r = k, p = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (x <= a[mid]) r = mid - 1, p = mid;
            else l = mid + 1;
        }
        // debug2(p, x);
        cout << b[p - 1] + (x - a[p - 1]) * (b[p] - b[p - 1]) / (a[p] - a[p - 1]) << ' ';
    }
    cout << '\n';
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