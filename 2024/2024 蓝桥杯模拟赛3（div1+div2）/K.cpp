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
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size() - 1;
    vector<vector<int>> dp(n + 2, vector<int> (n + 2));
    for (int i = s.size() - 1; i >= 0; i --) {
        for (int j = i + 1; j < s.size(); j ++) {
            if (s[i] > s[j]) dp[i][j] = 1;
            else if(s[i] < s[j]) dp[i][j] = 0;
            else dp[i][j] = dp[i + 1][j - 1];
            if (dp[i][j] == 1) ans ++;
        }
    }
    cout << ans  << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}