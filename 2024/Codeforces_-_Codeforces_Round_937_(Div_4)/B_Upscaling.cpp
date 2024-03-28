/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-28 22:46:21
 *
 * Problem: B. Upscaling
 * Contest: Codeforces - Codeforces Round 937 (Div. 4)
 * URL:     https://codeforces.com/contest/1950/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
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
const int N = 30;
const int INF = 0x3f3f3f3f;

using namespace std;

// char a[N][N];

void solve() {
    int n, f;
    cin >> n;
    vector<vector<char>> a(n * 2 + 1, vector<char> (n * 2 + 1, '#'));
    for (int i = 1, k = 1; i <= n * 2; i += 2, k ++) {
        if (k & 1) f = 1;
        else f = 0;
        for (int j = 1; j <= n * 2; j += 2) {
            if (f) {
                a[i][j] = '#';
                a[i + 1][j] = '#';
                a[i][j + 1] = '#';
                a[i + 1][j + 1] = '#';
            } else {
                a[i][j] = '.';
                a[i + 1][j] = '.';
                a[i][j + 1] = '.';
                a[i + 1][j + 1] = '.';
            }
            f ^= 1;
        }
    }
    for (int i = 1; i <= n * 2; i ++) {
        for (int j = 1; j <= n * 2; j ++) {
            cout << a[i][j];
        }
        cout << endl;
    }
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