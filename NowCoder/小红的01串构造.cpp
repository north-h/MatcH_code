/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-19 19:43:14
 *
 * Problem: 小红的01串构造
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/69695/C
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
    int n, k, t;
    cin >> n >> k >> t;
    if(k > n || t + 1 > n || t + 1 > k)cout << -1 << endl;
    else {
        vector<int> ans;
        for(int i = 0; i < t + 1; i++)ans.push_back(1);
        int k1 = k - (t + 1);
        int k0 = n - k;
        for(int i = 0; i < min(k1, k0); i++) {
            cout << "0 1 ";
        }
        if(k1 > k0) {
            cout << -1 << endl;
            return ;
        } else {
            for(int i = 0; i < k0 - k1; i++)ans.push_back(0);
        }
        for(auto i : ans)cout << i;
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