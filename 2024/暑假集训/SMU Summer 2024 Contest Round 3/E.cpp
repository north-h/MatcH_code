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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    n = min(n, 8ll);
    map<int, vector<int>> mp;
    for (int i = 0; i < 1 << n; i ++) {
        int sum = 0;
        vector<int> t;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) {
                sum += a[j + 1];
                t.push_back(j + 1);
            }
        }
        if (!t.size()) continue;
        if (mp.count(sum % 200)) {
            cout << "Yes" << '\n';
            cout << mp[sum % 200].size() << ' ';
            for (auto j : mp[sum % 200]) cout << j << ' ';
            cout << '\n';
            cout << t.size() << ' ';
            for (auto j : t) cout << j << ' ';
            cout << '\n';
            return ;
        } else mp[sum % 200] = t;
    }
    cout << "No" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}