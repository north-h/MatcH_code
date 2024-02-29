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
    string s;
    cin >> n >> s;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string sans = s;
    auto dfs = [&] (auto dfs, int u, int f, char op) -> bool {
        // debug2(u, op);
        if (s[u] != op && s[u] != '?') return false;
        sans[u] = op;
        char o;
        if (op == 'd') o = 'p'; 
        else o = 'd';
        for (auto i : g[u]) {
            if (i == f) continue;
            if (!dfs(dfs, i, u, o))return false;
        }
        return true;
    };
    int ans = -1;
    // debug1(s[0]);
    if (s[0] == 'd') ans = dfs(dfs, 0, -1, 'd');
    else if (s[0] == 'p') ans = dfs(dfs, 0, -1, 'p');
    else {
        ans = (dfs(dfs, 0, -1, 'd') || dfs(dfs, 0, -1, 'p'));
        // debug1(dfs(dfs, 0, -1, 'p'));
    }
    if (ans) cout << sans << endl;
    else cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}