/*
 * =========================================================
 * Author:  north_h
 * Time:    2024-04-05 19:48:45 ms
 *
 * Problem: 小A的数字
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/78306/C
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
 * =========================================================
 */

// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
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
    string s;
    cin >> s;
    string sans;
    int sum = 0;
    char op = s.back();
    for (int i = s.size() - 1; i >= 0; i --) {
        if (s[i] != '0') {
            sans += '0';
            sum = sum * 10;
        } else {
            sans += '1', sum = sum * 10 + 1;
        }
    }
    reverse(sans.begin(), sans.end());
    if (sum == 0) {
        if (op == '1') sans.back() += 2;
        else sans.back() ++;
    }
    int ans = 0;
    for (auto i : sans) ans = ans * 10 + (i - '0');
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