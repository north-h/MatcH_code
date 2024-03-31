/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-03-30 20:00:44 ms
 *
 * Problem: D - Popcount and XOR
 * Contest: AtCoder - AtCoder Beginner Contest 347
 * URL:     https://atcoder.jp/contests/abc347/tasks/abc347_d
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
    int a, b, C;
    cin >> a >> b >> C;
    int c= 0;
    for (int i = 60; i >= 0; i --) {
        if (C >> i & 1) c ++;
    }
    int sa = 0, sb = 0;
    __int128 sum = 0;
    if (a + b < c) cout << -1 << endl;
    else {
        int ca = a, cb = b, f = 0;
        for (int i = 0; i <= 60; i ++) {
            if ((C >> i & 1) && c > 0) {\
                // debug1(i);
                if (ca > cb) {
                    sum = sa + (1ll << i);
                    if (sum > (1ll << 60)) {
                        cout << -1 << endl;
                        return ;
                    }
                    sa += (1ll << i);
                    ca --;
                } else {
                    sum = sb + (1ll << i);
                    if (sum > (1ll << 60)) {
                        cout << -1 << endl;
                        return ;
                    }
                    sb += (1ll << i);
                    cb --;
                }
                c --;
            }
        }
        if (ca != cb) {
            cout << -1 << endl;
            return ;
        }
        for (int i = 0; i <= 60; i ++) {
            if (!(sa >> i & 1) && !(sb >> i & 1) && ca) {
                sum = sa + (1ll << i);
                if (sum > (1ll << 60)) {
                    cout << -1 << endl;
                    return ;
                }
                sa += (1ll << i);
                sum = sa + (1ll << i);
                if (sum > (1ll << 60)) {
                    cout << -1 << endl;
                    return ;
                }
                sb += (1ll << i);
                ca --;
            }
        }
    }
    cout << sa << ' ' << sb << endl;
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