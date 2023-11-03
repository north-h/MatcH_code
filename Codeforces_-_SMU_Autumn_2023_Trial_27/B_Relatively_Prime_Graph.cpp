/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-01 13:08:06
 *
 * Problem: B. Relatively Prime Graph
 * Contest: Codeforces - SMU Autumn 2023 Trial 27
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481919/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
const int N = 100010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int  n, m;
    cin >> n >> m;
    if(m < n - 1) {
        cout << "Impossible" << endl;
        return ;
    }
    vector<PII> ans;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(__gcd(i, j) == 1) {
                ans.push_back({i, j});
                if(ans.size() == m) {
                    cout << "Possible" << endl;
                    for(auto [x, y] : ans)cout << x << ' ' << y << endl;
                    return ;
                }
            }
        }
    }
    cout << "Impossible" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}