/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-05-03 16:38:02 ms
 *
 * Problem:  Number Game
 * Contest: Virtual Judge - CodeForces
 * URL:     https://vjudge.net/problem/CodeForces-1749C#author=GPT_zh
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int k = n; k >= 0; k --) {
        vector<int> b = a;
        bool f = true;
        for (int i = 1; i <= k; i ++) {
            sort(b.begin() + 1, b.end());
            int x = k - i + 1;
            int p = -1;
            for (int j = b.size() - 1; j >= 1; j --) {
                if (b[j] <= x) {
                    p = j;
                    break;
                }
            }
            if (p == -1) { f = false; break; }
            for (int j = p; j < b.size() - 1; j ++) {
                b[j] = b[j + 1];
            }
            b.pop_back();
            b[1] += x;
        }
        if (f) {
            cout << k << '\n';
            return ;
        }
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