/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-05-07 15:49:37 ms
 *
 * Problem: C. 3SUM Closure
 * Contest: Codeforces - SMU Spring 2024 Personal Round 1
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/522675/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
// using ll = long long;

void solve() {
    int n; cin >> n;
    int sum = 0;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
        mp[a[i]] ++;
    }
    if (n == 3) {
        if (!mp.count(sum)) cout << "NO" << '\n';
        else cout << "YES" << '\n';
        return ;
    }
    if (n == 4) {
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                for (int k = j + 1; k <= n; k ++) {
                    int x = a[i] + a[j] + a[k];
                    if (!mp.count(x)) {
                        cout << "NO" << '\n';
                        return ;
                    }
                }
            }
        }
        cout << "YES" << '\n';
        return ;
    }
    if (mp[0] == n) {
        cout << "YES" << '\n';
        return ;
    }
    if (mp[0] == n - 1) {
        cout << "YES" << '\n';
        return ;
    }
    if (mp[0] == n - 2 && sum == 0) {
        cout << "YES" << '\n';
        return ;
    }
    cout << "NO" << '\n';
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