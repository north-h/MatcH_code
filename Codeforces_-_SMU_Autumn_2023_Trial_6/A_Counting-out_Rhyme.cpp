/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-02 10:56:43
 *
 * Problem: A. Counting-out Rhyme
 * Contest: Codeforces - SMU Autumn 2023 Trial 6
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475592/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int t = n;
    vector<bool> vis(n + 1, false);
    int pos = 1;
    for(int i = 0; i < m; i++, t--) {
        int x;
        cin >> x;
        x %= t;
        if(x != 0)pos++;
        if(pos > n)pos = 1;
        for(int j = 1; j <= x; j++, pos++) {
            // debug1(pos);
            if(pos > n)pos = 1;
            while(vis[pos]) {
                pos++;
                if(pos > n)pos = 1;
            }
        }
        if(x != 0)pos--;
        vis[pos] = true;
        cout << pos << ' ';
        while(vis[pos]) {
            pos++;
            if(pos > n)pos = 1;
        }
    }
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}