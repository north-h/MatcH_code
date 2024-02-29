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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = INF;
    auto dfs = [&](auto dfs, int p, int c) -> void {
        if (p > n) {
            int sum = 0;
            for (int i = 1; i <=n; i ++) {
                sum += a[i];
            }
            if (sum == 0) ans = min(ans, c);
        }
        a[p] = -a[p];
        dfs(dfs, p + 1, c + 1);
        a[p] = -a[p];

        dfs(dfs, p + 1, c);
    };
    // dfs(dfs, 1, 0);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}