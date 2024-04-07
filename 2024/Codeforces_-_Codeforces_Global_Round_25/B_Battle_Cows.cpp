/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-04-07 00:19:45
 *
 * Problem: B. Battle Cows
 * Contest: Codeforces - Codeforces Global Round 25
 * URL:     https://codeforces.com/contest/1951/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first;
#define se second;
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
// #define LOCAL
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;
using ll = long long;
using PII = pair<int, int>;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int x = a[p];
    auto get = [&](vector<int> t) -> int{
        int res = 0;
        int win = a[1];
        for (int i = 2; i <= n; i ++) {
            if (win < a[i]) win = a[i];
            if (win == x) res ++;
        }
        return res;
    };
    swap(a[1], a[p]);
    int ans = get(a);
    swap(a[1], a[p]);
    for (int i = 1; i <= n; i ++) {
        if (a[i] > x) { 
            swap(a[i], a[p]);
            break;
        }
    }
    ans = max(ans, get(a));
    cout << ans << endl;
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