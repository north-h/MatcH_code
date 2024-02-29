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
const int mod = 1e9 + 7;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    s = " " + s;
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i <= n; i ++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    // debug1(dp[4]);
    auto check = [&](string s1, string s2) -> bool {
        for (int i = 0; i < s2.size(); i ++) {
            if (s2[i] == '_') continue;
            if (s1[i] != s2[i]) return false;
        }
        return true;
    };
    int ans = 0;
    vector<string> a = {"mygo", "m_ygo", "my_go", "myg_o", "m_y_go", "m_yg_o", "my_g_o", "m_y_g_o"};
    for (int i = 1; i < n; i ++) {
        for (auto j : a) {
            string str = s.substr(i, (int)j.size());
            if (check(str, j)) {
                // debug2(str, j);
                // debug1(i);
                ans += dp[i - 1] * dp[n - (i + (int)j.size() - 1)];
                ans %= mod; 
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}