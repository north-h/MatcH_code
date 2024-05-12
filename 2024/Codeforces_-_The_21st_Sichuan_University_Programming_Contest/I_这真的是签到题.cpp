/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-05-12 10:29:48
 *
 * Problem: I. 这真的是签到题
 * Contest: Codeforces - The 21st Sichuan University Programming Contest
 * URL:     https://codeforces.com/gym/104377/problem/I
 * MemoryL: 512 MB
 * TimeL:   1000 ms
 * ==================================================================================
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
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    sort(a.begin(), a.end());
    for (int i = n; i >= 1; i --) {
        // debug1(a[i]);
        int x = a[i];
        bool f = true;
        for (int j = 2; j < x / j; j ++) {
            if (x % j != 0) continue;
            while (x % j == 0) x /= j;
            if (!mp.count(j)) {
                f = false;
                break;
            }
        }
        if (x > 1 && !mp.count(x)) f = false;
        if (f) {
            cout << a[i] << '\n';
            return ;
        }
    }
    cout << - 1 << '\n';
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