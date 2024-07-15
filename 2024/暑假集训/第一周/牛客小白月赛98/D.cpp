// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 510;
const int INF = 0x3f3f3f3f;

using namespace std;

int n, L, R; 
string s;
int dp[N][N]; 

void solve() {
    cin >> n >> L >> R;
    cin >> s;
    s = " " + s;
    vector<int> s1(n + 1), s0(n + 1);
    for (int i = 1; i <= n; i ++) {
        s1[i] = s1[i - 1] + (s[i] == '1');
        s0[i] = s0[i - 1] + (s[i] == '0');
    }
    for (int len = 1; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            for (int k = l; k < r; k ++) {
                int C0 = s0[k] - s0[l - 1];
                int C1 = s1[r] - s1[k];
                int D = abs(C0 - C1);
                if (D >= L && D <= R) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[l + 1][r] + 1);
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}