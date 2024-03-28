/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-28 22:46:34
 *
 * Problem: D. Product of Binary Decimals
 * Contest: Codeforces - Codeforces Round 937 (Div. 4)
 * URL:     https://codeforces.com/contest/1950/problem/D
 * MemoryL: 256 MB
 * TimeL:   3000 ms
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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = (int)to_string(n).size();
    for (int i = (1 << x) - 1; i >= 2; i --) {
        vector<int> t;
        int y = i;
        while (y) {
            t.push_back(y % 2);
            y /= 2;
        }
        reverse(t.begin(), t.end());
        int sum = 0;
        for (auto j : t) sum = sum * 10 + j;
        while (n % sum == 0 ) {
            n /= sum;
            if (n == 1) {
                cout << "YES" << endl;
                return ;
            }
        }
    }
    if (n == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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