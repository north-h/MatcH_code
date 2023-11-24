/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-24 23:30:37
 *
 * Problem: A. Line Trip
 * Contest: Codeforces - Educational Codeforces Round 158 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1901/problem/A
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
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    for(int i = 1; i <= x; i++) {
        int cnt = i;
        bool ok = true;
        for(int j = 1; j <= x; j++) {
            if(cnt == 0) {
                ok = false;
                break;
            }
            cnt--;
            if(mp.count(j))cnt = i;
            // debug2(cnt, j);
        }
        for(int j = x - 1; j >= 0; j--) {
            if(cnt == 0) {
                ok = false;
                break;
            }
            cnt--;
            if(mp.count(j))cnt = i;
        }
        if(ok) {
            cout << i << endl;
            return ;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}