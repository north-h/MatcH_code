#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<ll, ll>;

const int N = 2e6 + 10, M = 210;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
ll n;
vector<int>ve[44];
int vi[44];
int ans;
int cnt = 2e7;
bool ok = false;
void dfs(int x, int len) {
    if (ok) return ;
    if ((double)clock() / CLOCKS_PER_SEC >= 0.80) {
        ok = true;
        return ;
    }
    ans = max(len, ans);
//  if(cnt--<0) return ;
    vector<int>to;
    for (int v : ve[x]) if (!vi[v]) to.push_back(v), vi[v] = 1;
    for (int v : to) {
        dfs(v, len + 1);
//      if(cnt--<0) break;
    }
    for (int v : to) vi[v] = 0;
}
void solve() {
    int m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        memset(vi, 0, sizeof vi);
        vi[i] = 1;
        dfs(i, 1);
        // if(cnt--<0) break;
        if (ok) break;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int O_o = 1;
//  cin >> O_o;
    while (O_o--) solve();
    return 0;
}
//make it count
//开ll plz