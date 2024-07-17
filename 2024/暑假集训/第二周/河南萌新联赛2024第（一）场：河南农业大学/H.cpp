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
    vector<int> a(n + 1);
    int mx = 0, sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    sort(a.begin() + 1, a.end());
    if (mx == 1) {
        cout << sum - mx + mx + n << '\n';
    } else {
        cout << sum - mx + mx * n << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}