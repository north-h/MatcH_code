/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-03-30 20:00:40 ms
 *
 * Problem: C - Ideal Holidays
 * Contest: AtCoder - AtCoder Beginner Contest 347
 * URL:     https://atcoder.jp/contests/abc347/tasks/abc347_c
 * MemoryL: 1024 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> d[i];
        d[i] %= (a + b);
        if (d[i] == 0) d[i] = a + b;
    }
    if (d[1] > a) {
        cout << "No" << endl;
        return ;
    }
    int p = 0;
    for (int i = 2; i <= n; i ++) {
        if (d[i] > a) {
            if (d[i] - d[i - 1] <= b) {
                cout << "No" << endl;
                return ;
            }
            p = a - d[i - 1];
            break;
        }
    }
    for (int i = 1; i <= n; i ++) {
        int sp = (p + d[i]) % (a + b);
        if (sp == 0) sp = a + b;
        if (sp <= b && sp > a) {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
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