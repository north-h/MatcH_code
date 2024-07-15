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
    int n; cin >> n;
    vector<array<int, 2>> se;
    for (int i = 1, x, y; i <= n; i ++) {
        cin >> x >> y;
        se.push_back({x, y});
    }
    sort(se.begin(), se.end());
    priority_queue<int, vector<int>, greater<int>> q;
    int i = 0, t = 0, ans = 0;
    while (true) {
        if (!q.size()) {
            if (i == n) break;
            t = max(t, se[i][0]);
        }
        while (i < n && se[i][0] <= t) {
            q.push(se[i][0] + se[i][1]);
            i ++;
        }
        while (q.size() && q.top() < t) q.pop();
        if (q.size()) ans ++, q.pop();
        t ++;
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