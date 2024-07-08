// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define lf(x) fixed << setprecision(x)
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i <= c; i ++) {
        for (int j = 0; j <= c; j ++) {
            if (i + j > c || i + j > n) continue;
            priority_queue<int, vector<int>, greater<int>> q;
            int res = 0;
            for (int k = 1; k <= i; k ++) q.push(a[k]);
            for (int k = 1; k <= j; k ++) q.push(a[n - k + 1]);
            // debug1(c - i - j);
            for (int k = 1; k <= c - i - j && q.size(); k ++) {
                if (q.top() > 0) break;
                q.pop();
            }
            while (q.size()) res += q.top(), q.pop();
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}