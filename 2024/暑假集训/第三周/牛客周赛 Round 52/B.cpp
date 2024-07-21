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
    int a, b, n; cin >> a >> b >> n;
    int c = b / 2, v = c * 3, cv;
    if (v > n) {
        cv = n - (c - 1) * 3;
    } else {
        cv = n - v;
    }
    if (cv > a) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}