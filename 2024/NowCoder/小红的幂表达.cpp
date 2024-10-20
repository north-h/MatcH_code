/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-10-20 19:01:45
 *
 * Problem: 小红的幂表达
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/92662/B
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
    int n; cin >> n;
    int x = n, p;
    for (int i = 2; i <= n; i ++) {
        if (x % i == 0) {
            p = i;
            break;
        }
    }
    cout << n << '\n';
    int cnt, c = 0;
    x = n;
    while (x % p == 0) x /= p, c ++;
    cnt = c;
    // debug2(p, c);
    if (x != 1) {
        cout << "=" << n << '^' << 1 << '\n';
        return ;
    }
    while (cnt % 2 == 0 && cnt != 0) {
        cout << "=" << pow(p, cnt) << '^' << c / cnt << '\n';
        cnt /= 2;
    }
    if (cnt != 1) cout << "=" << pow(p, cnt) << '^' << c / cnt << '\n';
    cout << "=" << p << '^' << c << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}