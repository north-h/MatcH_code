/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-13 16:09:50
 *
 * Problem: F. Make it Divisible by 25
 * Contest: Codeforces - SMU Autumn 2023 Round 3(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470094/problem/F
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    ll n;
    cin >> n;
    string s;
    s = to_string(n);
    string ans;
    for(auto i : s) {
        if(i == '0' || i == '2' || i == '5' || i == '7' || i == '1')
            ans += i;
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