/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-12 00:14:55
 *
 * Problem: F. Ball in Berland
 * Contest: Codeforces - SMU Autumn 2023 Round 6
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/476122/problem/F
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> ac(k), bc(k);
    map<int, int> ma, mb;
    map<PII, int> mp;
    for(int i = 0; i < k; i++) {
        cin >> ac[i];
        ma[ac[i]]++;
    }
    for(int i = 0; i < k; i++) {
        cin >> bc[i];
        mb[bc[i]]++;
    }
    for(int i = 0; i < k; i++) {
        mp[ {ac[i], bc[i]}]++;
    }
    int ans = 0;
    int t = k;
    for(int i = 0; i < t; i++) {
        // mp[ {ac[i], bc[i]}]--;
        // ma[ac[i]]--;
        // mb[bc[i]]--;
        // k--;
        int aa = ma[ac[i]];
        int bb = mb[bc[i]];
        // debug2(aa, bb);
        int x = mp[ {ac[i], bc[i]}];
        // debug1(x);
        int y = (aa + bb - x);
        // debug1(y);
        ans += k - y;
    }
    cout << ans / 2 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}