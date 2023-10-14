/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-13 20:21:09
 *
 * Problem: P2670 [NOIP2015 普及组] 扫雷游戏
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P2670
 * MemoryL: 125 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(auto &i : g)cin >> i;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '*')cout << g[i][j];
            else {
                int ans = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    // debug2(x, y);
                    if(x < 0 || y < 0 || n <= x || y >= m || g[x][y] == '?')continue;
                    ans++;
                }
                cout << ans ;
            }
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}