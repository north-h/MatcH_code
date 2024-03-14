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
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<int> ans;
    for (int i = 1; i <= n; i ++) {
        vector<int> a(m + 1), dp(m + 1);
        dp[0] = 0;
        int lst = 0;
        for (int j = 1; j <= m; j ++) cin >> a[j];
        deque<int> dq;
        for (int j = 1; j <= m; j ++) {
            if (dq.size() && i - dq.front() + 1 > d + 2) dq.pop_front();
            while(dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= d + 2) {
                dp[dq.back()] = dp[lst] + a[dq.back()] + 1;
                lst = dq.back();
            }
        }
        ans.push_back(dp[m]);
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
    cout << endl;
    int c = 0;
    for (int i = 0; i < k; i ++) c += ans[i];
    cout << c + 2 << endl;
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