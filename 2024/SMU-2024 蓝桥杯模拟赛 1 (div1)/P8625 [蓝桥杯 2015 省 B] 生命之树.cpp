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
const int N = 100010;
const int INF = 0x3f3f3f3f;

using namespace std;

vector<int> g[N];
vector<ll> dp;
int ans = 0;

void dfs(int u, int f) {
    for(auto i : g[u]){
        if(i != f) {
            dfs(i, u);
            dp[u] += max(dp[i], 0ll);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> w(n + 1);
    dp.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        dp[i] = w[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}