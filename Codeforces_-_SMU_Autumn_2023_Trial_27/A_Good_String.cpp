/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-01 13:08:02
 *
 * Problem: A. Good String
 * Contest: Codeforces - SMU Autumn 2023 Trial 27
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/481919/problem/A
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
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    map<char, int> mp;
    for(auto i : s)mp[i]++;
    int ans = INF;
    for(auto [x, y] : mp) {
        ans = min(ans, n - y);
    }
    debug1(ans);
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            if(i == j)continue;
            int cnt = 0;
            for(int k = 0; k + 1 < s.size(); k++) {
                if((s[k] - '0' == i) && (s[k + 1] - '0') == j)
                    cnt++;
            }
            ans = min(ans, n - cnt * 2);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}