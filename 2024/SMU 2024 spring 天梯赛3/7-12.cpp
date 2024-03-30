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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        while (k --) {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    // for (int i = 0; i < n; i ++) {
    //     cout << i << ':';
    //     for (auto j : g[i]) cout << j << ' ';
    //     cout << endl;
    // }
    vector<string> ans;
    string T;
    auto dfs = [&] (auto dfs, int u, int f) ->void {
        for (auto i : g[u]) {
            if (i == f) continue;
            T.push_back(i + '0');
            dfs(dfs, i, u);
            T.pop_back();
        }
        ans.push_back(T);
    };
    T.push_back('0');
    dfs(dfs, 0, -1);
    sort(ans.begin(), ans.end(), [](string a, string b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a < b;
    });
    cout << ans[0].size() << endl;
    for (int i = 0; i < ans[0].size(); i ++) {
        cout << ans[0][i];
        if (i != ans[0].size()) cout << ' ';
    }
    // cout << endl;
}

int32_t main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}