/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-08-13 22:41:22
 *
 * Problem: D. Right Left Wrong
 * Contest: Codeforces - Codeforces Round 966 (Div. 3)
 * URL:     https://codeforces.com/contest/2000/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> s(n + 1);
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    int ans = 0;
    string ss; cin >> ss; ss = " " + ss;
    for (int i = 1, j = n; i < j;) {
        // debug2(i, j);
        if (ss[i] != 'L') i ++;
        if (ss[j] != 'R') j --;
        if (ss[i] == 'L' && ss[j] == 'R') {
            ans += s[j] - s[i - 1];
            i ++;
            j --;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}