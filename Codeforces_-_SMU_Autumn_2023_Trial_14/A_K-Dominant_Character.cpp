/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-10-14 14:02:02
 *
 * Problem: A. K-Dominant Character
 * Contest: Codeforces - SMU Autumn 2023 Trial 14
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/478090/problem/A
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
const int N = 110;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    s = " " + s;
    map<char, vector<int>> mp;
    for(int i = 1; i < s.size(); i++) {
        mp[s[i]].push_back(i);
    }
    int ans = INT_MAX;;
    int n = s.size() - 1;
    for(auto [x, y] : mp) {
        int res = -1;
        if(y.back() != n)y.push_back(n + 1);
        reverse(ALL(y));
        if(y.back() != 1)y.push_back(0);
        reverse(ALL(y));
        // cout << x << ':';
        // for(auto i : y)cout << i << ' ';
        // cout << endl;
        for(int i = 1; i < y.size(); i++) {
            res = max(res, y[i] - y[i - 1]);
        }
        if(res == -1)res = s.size() - 1;
        ans = min(ans, res);
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