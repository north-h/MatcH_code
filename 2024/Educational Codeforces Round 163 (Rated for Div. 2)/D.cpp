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
    string s;
    cin >> s;
    s = " " + s;
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < n; j ++) {
            if (s[i] == '?' || s[j] == '?' || s[i] == s[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < n; j ++) {
            if (dp[i][j] >= j - i) {
                ans = max(ans, (j - i) * 2);
            }
        }
    }
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