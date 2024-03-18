// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int, int>
#define endl '\n'
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define PI acos(-1)
//  #define LOCAL
const int N = 10010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<array<int, 2>> dp(210,{INF, INF});
    for (int i = 0; i < (int)a.size(); i ++) {
        dp[a[i]][1] = 1;
        for (int j = 0; j <= 200; j ++) {
            dp[j & a[i]][1] = min(dp[j & a[i]][1], dp[j][0] + 1);
        }
        for (int j = 0; j <= 200; j ++) dp[j][0] = dp[j][1];
    }
    if (dp[0][0] > n) cout << -1 << endl;
    else cout << n - dp[0][0] << endl;
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