// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define debug1(a) cout << #a << '=' << a << endl
#define debug2(a, b) cout << #a << '=' << a << ' ' << #b << '=' << b << endl
#define int long long
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    map<int, vector<int>> mp;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        int mn = (max(-x, 0ll) + i - 1) / i, mx = max((n - x) / i, 0ll);
        for (int j = mn; j <= mx; j ++) {
            mp[j].push_back(x + j * i);
        }
    }
    for (int i = 1; i <= m; i ++) {
        sort(mp[i].begin(), mp[i].end());
        int mex = 0;
        for (auto j : mp[i]) {
            if (j == mex) mex ++;
        }
        cout << mex << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}