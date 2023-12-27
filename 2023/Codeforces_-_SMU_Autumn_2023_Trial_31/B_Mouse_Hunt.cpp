/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-08 12:11:21
 *
 * Problem: B. Mouse Hunt
 * Contest: Codeforces - SMU Autumn 2023 Trial 31
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484047/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 200010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int fa[N], val[N], g[N];
int n;
bool vis[N], vi[N];
int ans, res;
bool ok;

int find(int x) {
    if(fa[x] != x)fa[x] = find(fa[x]);
    return fa[x];
}

int dfs1(int u) {
    if(vis[u])return u;
    vis[u] = true;
    return dfs1(g[u]);
}

void dfs2(int u, int s) {
    res = min(res, val[u]);
    if(ok)return ;
    if(u == s) {
        ok = true;
        return ;
    }
    vi[u] = true;
    dfs2(g[u], s);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)fa[i] = i;
    for(int i = 1; i <= n; i++)cin >> val[i];
    for(int i = 1; i <= n; i++) {
        cin >> g[i];
        int pa = find(i);
        int pb = find(g[i]);
        fa[pa] = pb;
    }
    map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        if(mp[find(i)] == 0) {
            mp[find(i)]++;
            res = INF;
            ok = false;
            // for(int i = 1; i <= n; i++)vi[i] = false;
            int s = dfs1(i);
            dfs2(g[s], s);
            ans += res;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}