// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> l[i] >> r[i];
    }
    int L = l[1], R = r[1];
    vector<PII> v;
    for (int i = 2; i <= n; i ++) {
        if (l[i] > R || r[i] < L) {
            v.push_back({L, R});
            L = l[i], R = r[i];
        }
        L = max(L, l[i]);
        R = min(R, r[i]);
    }
    if (L != v.back().fi || R != v.back().se) {
        v.push_back({L, R});
    }
    vector<array<int, 2>> dp((int)v.size() + 1);
    for (int i = 1; i < v.size(); i ++) {
        dp[i][0] = min(dp[i - 1][0] + abs(v[i].fi - v[i - 1].fi), dp[i - 1][1] + abs(v[i].fi - v[i - 1].se));
        dp[i][1] = min(dp[i - 1][0] + abs(v[i].se - v[i - 1].fi), dp[i - 1][1] + abs(v[i].se - v[i - 1].se));
    }
    int x = v.size() - 1;
    cout << min(dp[x][0], dp[x][1]) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}