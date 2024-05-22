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
    int x, y; cin >> x >> y;
    string a = "cqust", b = "tsuqc";
    int mn = min(x, y), c = max(x, y) - min(x, y);
    string s;
    if (x > y) {
        for (int i = 1; i <= mn; i ++) {
            if (s.empty()) s = a + b.substr(1);
            else s += a.substr(1) + b.substr(1);
        }
        if (s.size() && c) s += a.substr(1), c --;
        for (int i = 1; i <= c; i ++) s += a;
    } else {
        for (int i = 1; i <= mn; i ++) {
            if (s.empty()) s = b + a.substr(1);
            else s += b.substr(1) + a.substr(1);
        }
        if (s.size() && c) s += b.substr(1), c --;
        for (int i = 1; i <= c; i ++) s += b;
    }
    cout << s << '\n';
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