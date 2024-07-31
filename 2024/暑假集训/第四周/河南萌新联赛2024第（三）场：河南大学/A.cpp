// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int PI = acos(-1);

using namespace std;

void solve() {
    int n; cin >> n;
    double ans = INF, res1, res2;
    while (n --) {
        int p, a; cin >> p >> a;
        double x = p * 1.0 / a;
        if (ans < abs(x - PI)) {
            ans = abs(x - PI);
            res1 = p;
            res2 = a;
        }
    }
    cout << res1 << ' ' << res2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}