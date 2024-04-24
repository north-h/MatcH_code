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

void solve(int t) {
    int n, m;
    cin >> n >> m;
    cout << "Case #" << t << ": ";
    if (n == 1) cout << lf(6) << 1.0 << ' ';
    else cout << lf(6) <<  0.5 << ' ';
    cout << lf(6) << (1 + (m - 1) * 0.5) / m << '\n';
}


int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    for (int i = 1; i <= h_h; i ++) solve(i);
    return 0;
}