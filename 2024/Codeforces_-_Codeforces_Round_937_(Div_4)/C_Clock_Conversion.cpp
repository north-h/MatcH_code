/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-03-28 22:46:30
 *
 * Problem: C. Clock Conversion
 * Contest: Codeforces - Codeforces Round 937 (Div. 4)
 * URL:     https://codeforces.com/contest/1950/problem/C
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
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int h, m;
    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    if (h == 0){
        printf("%02d:%02d AM\n", 12, m);
        return ;
    }
    int sum = h * 60 + m;
    if (sum < 12 * 60) {
        printf("%02d:%02d AM\n", h, m);
    } else {
        if (h == 12) printf("%02d:%02d PM\n", 12, m);        
        else printf("%02d:%02d PM\n", h - 12, m);        
    }
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}