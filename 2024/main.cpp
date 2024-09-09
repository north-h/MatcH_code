#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define ll long long
using namespace std;
const int N = 109;
const int mod = 998244353;
int dp[N][N][N], n, m;
string S, T;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> S >> T;
    n = S.length();
    m = T.length();
    S = ' ' + S;
    T = ' ' + T;
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= m + 1; j++)
            for (int t = 0; t < j; t++)
                dp[i][j][t] = 1;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++)
            for (int r = l; r <= m; r++) {
                for (int k = l - 1; k <= r; k++)
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 1][k + 1][r]) % mod;
                for (int k = l - 1; k < r; k++)
                    if (S[i] == T[k + 1])
                        dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 1][k + 2][r]) % mod;
            }
    }
    cout << dp[n][1][m] << '\n';
    //system("pause");  // 交之前记得注释一下，关流的时候不会显示输出
    return 0;
}