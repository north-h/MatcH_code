/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-28 12:38:48
 *
 * Problem: A. New Skateboard
 * Contest: Codeforces - SMU Autumn 2023 Trial 2
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475545/problem/A
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
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    if(s[0] == '0' || s[0] == '4' || s[0] == '8')ans++;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '0' || s[i] == '4' || s[i] == '8') {
            // cout << i << ' ';
            if(s[i - 1] % 2 == 0)ans += i + 1;
            else ans++;
        } else if(s[i] == '2' || s[i] == '6') {
            if(s[i - 1] & 1)ans += i;
        }
    }
    // cout << endl;
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}