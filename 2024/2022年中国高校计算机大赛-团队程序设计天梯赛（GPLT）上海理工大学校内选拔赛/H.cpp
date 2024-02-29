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

using namespace std;

void solve() {
    int n, H;
    cin >> n >> H;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    vector<int> pre(n + 1), dp(H + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n;i ++) {
        for (int j = H; j >= a[i]; j --) {
            if (dp[j - a[i]] == INF) continue;
            if (dp[j] >= dp[j - a[i]] + 1) {
                dp[j] = dp[j - a[i]] + 1;
                pre[j] = i;
            }
        }
    }
    if (dp[H] == INF) {
        cout << -1 << endl;
        return ;
    }
    cout << dp[H] << endl;
    while (H) {
        cout << a[pre[H]] <<' ';
        H -= a[pre[H]];
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}