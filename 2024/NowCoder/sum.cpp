/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-11 19:27:15
 *
 * Problem: sum
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/91355/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cerr << #a << '=' << a << endl
#define debug2(a, b) cerr << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, sum; cin >> n >> sum;
    vector<int> a(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i], res += a[i];
    sort(a.begin() + 1, a.end());
    int cv = res - sum;
    if (cv == 0) {
        cout << 0 << '\n';
        return ;
    }
    auto check = [&](int x) -> bool {
        auto b = a;
        if (cv > 0) {
            for (int i = n; i >= n - x + 1; i --) b[i] = -10000;
        } else {
            for (int i = 1; i <= x; i ++) b[i] = 10000;
        }
        int res = 0;
        for (int i = 1; i <= n; i ++) res += b[i];
        if (cv > 0) return res <= sum;
        else return res >= sum;
    };
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        // debug2(l, r);
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
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