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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    if (k >= n) {
        cout << n << '\n';
        return ;
    }
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= k; i ++) {
        Q.push(a[i]);
    }
    int ans = k;
    for (int i = k + 1; i <= n; i ++) {
        if (Q.size() && Q.top() < a[i]) {
            if (m - Q.top() > 0) {
                ans ++;
                m -= Q.top();
                Q.pop();
                Q.push(a[i]);
            } else if (m - a[i] > 0) {
                ans ++;
                m -= a[i];
            } else break;
        } else {
            if (m - a[i] > 0) {
                ans ++;
                m -= a[i];
            } else break;
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