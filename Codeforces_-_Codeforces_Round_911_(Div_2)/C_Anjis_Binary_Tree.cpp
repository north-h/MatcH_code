/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-27 00:11:41
 *
 * Problem: C. Anji's Binary Tree
 * Contest: Codeforces - Codeforces Round 911 (Div. 2)
 * URL:     https://codeforces.com/contest/1900/problem/C
 * MemoryL: 256 MB
 * TimeL:   2500 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
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
const int N = 300010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int ans, res;
int edge[N][2];
string s;
int n;

void dfs(int x, int cnt) {
    int l = edge[x][0], r = edge[x][1];
    if(l == 0 && r == 0) {
        ans = min(ans, cnt);
        return ;
    }
    if(l) dfs(l, cnt + (s[x] != 'L'));
    if(r) dfs(r, cnt + (s[x] != 'R'));
}

void solve() {
    cin >> n >> s;
    s = " " + s;
    for(int i = 1; i <= n; i++) {
        cin >> edge[i][0] >> edge[i][1];
    }
    ans = INF;
    dfs(1, 0);
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}