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
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        sum ^= x;
    }
    cout << sum << '\n';
    vector<int> b;
    while (sum) {
        b.push_back(sum % 2);
        sum /= 2;
    }
    reverse(b.begin(), b.end());
    for (auto i : b) cout << i << ' ';
    cout << '\n';
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}