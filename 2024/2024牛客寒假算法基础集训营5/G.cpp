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
const int N = 2000010;
const int INF = 0x3f3f3f3f;

using namespace std;

int vis[N];

void prework() {
    vis[0] = vis[1] = 0;
    for (int i = 2; i < N; i ++) {
        if (!vis[i]) {
            for (int j = i + i; j < N; j += i) {
                vis[j] = 1;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    auto dfs = [&](auto dfs, int n) -> void {
        for (int i = 1; i <= n; i ++) {
            if (!vis[n + i]) {
                // debug1(i);
                dfs(dfs, i - 1);
                for (int j = n; j >= i; j --) ans.push_back(j);
                break;
            }
        }
    };
    dfs(dfs, n);
    if (ans.size() < n) cout << -1 << endl;
    else {
        for (auto i : ans) cout << i << ' ';
        cout << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    prework();
    int h_h = 1;
//     cin >> h_h;
    while (h_h--)solve();
    return 0;
}