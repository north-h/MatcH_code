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

int ksm(int a, int b) {
    int res = 1;
    while(b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

int inv(int x) {
    return ksm(x, mod - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ch(3), cz(3);
    for (int i = 1, x; i <= n;i ++) {
        cin >> x;
        ch[x] ++;
    }
    for (int i = 1, x; i <= m;i ++) {
        cin >> x;
        cz[x] ++;
    }
    vector<vector<int>> dp(ch[1] + 1, vector<int>(cz[1] + 1));
    for (int i = 0; i <= ch[1]; i++) {
        for (int j = 0; j <= cz[1]; j ++) {
            if (!i && !j) continue;
            int pi = i * inv(i + ch[2]) % mod * cz[2] % mod * inv(j + cz[2]) % mod;
            int pj = j * inv(j + cz[2]) % mod * ch[2] % mod * inv(i + ch[2]) % mod;
            dp[i][j] = 1;
            if (i > 0) dp[i][j] += dp[i - 1][j] * pi % mod;
            if (j > 0) dp[i][j] += dp[i][j - 1] * pj % mod;
            dp[i][j] = (dp[i][j] % mod * inv(pi + pj)) % mod;
        }
    }
    cout << dp[ch[1]][cz[1]] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}