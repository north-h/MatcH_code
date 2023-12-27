/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-15 23:20:04
 *
 * Problem: 营救普雷赛斯
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69327/A
 * MemoryL: 524288 MB
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int c;
    cin >> c;
    vector<int> a(c), b(c), vis(c);
    for(int i = 0; i < c; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < c; i++) {
        cin >> b[i];
    }
    int h = 0;
    int cnt = 0;
    while(vis[h] == 0) {
        vis[h] = 1;
        h += a[h];
        cnt++;
        if(h >= c) {
            cout << cnt << endl;
            return ;
        }
        h -= b[h];
        // debug1(h);
        h = max(h, 0ll);
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}