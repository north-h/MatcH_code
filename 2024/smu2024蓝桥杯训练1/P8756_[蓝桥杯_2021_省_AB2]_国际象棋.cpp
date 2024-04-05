/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-02 13:06:40 ms
 *
 * Problem: P8756 [蓝桥杯 2021 省 AB2] 国际象棋
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P8756?contestId=165469
 * MemoryL: 128 MB
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
const int N = 50;
const int INF = 0x3f3f3f3f;

using namespace std;

int C[N][N];

void comb(){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(!j) { C[i][j] = 1;continue; }
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

void solve() {
    comb();
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1) cout << m * n << endl;
    else if (n == 1) cout << C[m][k] << endl;
    else cout << n * m * k << endl;
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