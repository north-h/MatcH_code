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
const int N = 10010;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

using namespace std;

int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res  = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res % mod;
}

int inv[1010];

void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), cnt(3);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        inv[i] = ksm(i, mod - 2);
    }
    debug1(inv[3]);
    vector<vector<int>> dp(n + 1, vector<int>(cnt[2] + 1));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= cnt[2]; j++) {
            dp[i][j] = ((i - j)  * inv[i] % mod * ((1 - dp[i - 1][j] + mod) % mod)) % mod;
            dp[i][j] = (dp[i][j] + j * inv[i] % mod * ((1 - dp[i][j - 1] + mod) % mod) % mod) % mod;
        }
    }
    cout << dp[n][cnt[2]] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}