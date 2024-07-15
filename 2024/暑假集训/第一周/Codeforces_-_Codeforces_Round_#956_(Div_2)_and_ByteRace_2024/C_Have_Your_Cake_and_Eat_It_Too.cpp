/*
 * ==============================================================
 * Author:  north_h
 * Time:    2024-07-08 13:30:59 ms
 *
 * Problem: C. Have Your Cake and Eat It Too
 * Contest: Codeforces - Codeforces Round #956 (Div. 2) and ByteRace 2024
 * URL:     https://codeforces.com/contest/1983/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==============================================================
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
    vector<int> a(n + 1), b(n + 1), c(n + 1), sa(n + 1), sb(n + 1), sc(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i], sa[i] = sa[i - 1] + a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i], sb[i] = sb[i - 1] + b[i];
    for (int i = 1; i <= n; i ++) cin >> c[i], sc[i] = sc[i - 1] + c[i];
    int avg = (sa[n] + 2) / 3;
    string s = "abc";
    do {
        vector<int> va, vb, vc;
        if (s[0] == 'a') va = sa;
        else if (s[0] == 'b') va = sb;
        else va = sc;
        if (s[1] == 'a') vb = sa;
        else if (s[1] == 'b') vb = sb;
        else vb = sc;
        if (s[2] == 'a') vc = sa;
        else if (s[2] == 'b') vc = sb;
        else vc = sc;
        for (int i = 1; i <= n - 2; i ++) {
            if (va[i] < avg) continue;
            int l = i + 1, r = n - 1, ans = -1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (vb[mid] - vb[i] >= avg) r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            if (ans != -1 && vc[n] - vc[ans] >= avg) {
                // debug1(s);
                if (s == "abc")
                    cout << 1 << ' ' << i << ' ' << i + 1 << ' ' << ans << ' ' << ans + 1 << ' ' << n << '\n';
                if (s == "acb")
                    cout << 1 << ' ' << i << ' ' << ans + 1 << ' ' << n << ' ' << i + 1 << ' ' << ans << '\n';
                if (s == "bac")
                    cout << i + 1 << ' ' << ans << ' ' << 1 << ' ' << i << ' ' << ans + 1 << ' ' << n << '\n';
                if (s == "bca")
                    cout << ans + 1 << ' ' << n << ' ' << 1 << ' ' << i << ' ' << i + 1 << ' ' << ans << '\n';
                if (s == "cab")
                    cout << i + 1 << ' ' << ans << ' ' << ans + 1 << ' ' << n << ' ' << 1 << ' ' << i << '\n';
                if (s == "cba")
                    cout << ans + 1 << ' ' << n << ' ' << i + 1 << ' ' << ans << ' ' << 1 << ' ' << i << '\n';
                return ;
            }
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << -1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}