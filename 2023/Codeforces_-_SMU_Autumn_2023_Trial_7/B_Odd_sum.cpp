/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-03 11:15:19
 *
 * Problem: B. Odd sum
 * Contest: Codeforces - SMU Autumn 2023 Trial 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475593/problem/B
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
    int n;
    cin >> n;
    vector<int> a, b, c, d;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        if(x > 0) {
            if(x & 1)a.push_back(x);
            else b.push_back(x);
        } else {
            if(abs(x) & 1)c.push_back(x);
        }
    }
    sort(ALL(a));
    sort(rALL(c));
    int sa = 0, sb = 0, sc = 0, sd = 0;
    for(auto i : a)sa += i;
    for(auto i : b)sb += i;
    int res = sa + sb;
    if(res & 1)cout << res << endl;
    else {
        if(a.size() && c.size())cout << max(res - a[0], res + c[0]) << endl;
        else if(!a.size())cout << res + c[0] << endl;
        else cout << res - a[0] << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}