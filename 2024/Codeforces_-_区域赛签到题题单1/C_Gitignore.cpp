/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-12 17:15:35 ms
 *
 * Problem: C. Gitignore
 * Contest: Codeforces - 区域赛签到题题单1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/514966/problem/C
 * MemoryL: 1024 MB
 * TimeL:   1000 ms
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
    int n, m;
    cin >> n >> m;
    map<string, int> p2;
    vector<string> file(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> file[i];
        // debug1(file[i]);
    }
    for (int i = 1; i <= m; i ++) {
        string s; cin >> s;
        string str;
        for (int j = 0; j < s.size(); j ++) {
            if (s[j] == '/') p2[str] = 1;
            str += s[j];
        }
        p2[str] ++;
    }
    int ans = n;
    for (int i = 1; i <= n; i ++) {
        string str;
        for (int j = 0; j < file[i].size(); j ++) {
            if (file[i][j] == '/') {
                if (p2[str] == 0) {
                    p2[str] = 2;
                } else if (p2[str] == 2) {
                    ans --;
                    break;
                }
            }
            str += file[i][j];
        }
    }
    cout << ans << '\n';
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