/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-14 15:05:19
 *
 * Problem: B. Ordinary Numbers
 * Contest: Codeforces - Codeforces Round 719 (Div. 3)
 * URL:     https://codeforces.com/contest/1520/problem/B
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
const int N =  100010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

map<int, int> mp;

void solve() {
    int  n;
    cin >> n;
    int ans = 0;
    for(auto [x, y] : mp) {
        if(x <= n)ans++;
        else break;
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    for(int i = 1; i <= 9; i++) {
        for(int j = i; j <= 1e9; j = j *  10 + i) {
            mp[j] = 1;
        }
    }
    // for(auto [x, y] : mp)cout << x << ' ';
    // cout << endl;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}