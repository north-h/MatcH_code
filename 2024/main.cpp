<<<<<<< HEAD
/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-04 15:48:23
 *
 * Problem: C. Cards Partition
 * Contest: Codeforces - Codeforces Round 975 (Div. 2)
 * URL:     https://codeforces.com/contest/2019/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010, INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cc(n + 1);
    int sum = 0, mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> cc[i];
        mx = max(mx, cc[i]);
        sum += cc[i];
    }
    // debug2(mx, sum);
    auto check = [&](int x) -> bool {
        if (x == 1) return true;
        int cv = sum / x, vc = x - sum % x, ok = 0;
        cv += k / x;
        // if (sum % x && k <= vc) ok = 0;
        if (sum % x == 0) ok = 1;
        if (k >= vc) cv ++, vc = 0, k -= vc, ok = 1;
        if (mx > cv || !ok) return false;
        return true;
    };
    for (int i = n; i >= 1; i --) {
        if (check(i)) {cout << i << "\n"; return ;}
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}
=======
>>>>>>> cfd803fb0436d6d8343a504f65c999d27c2af9bf
