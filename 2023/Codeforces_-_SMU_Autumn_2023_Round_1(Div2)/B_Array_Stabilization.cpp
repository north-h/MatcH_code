/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-09 16:33:40
 *
 * Problem: B. Array Stabilization
 * Contest: Codeforces - SMU Autumn 2023 Round 1(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470092/problem/B
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
    int  n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    if(n == 2) {
        cout << 0 << endl;
        return ;
    }
    sort(ALL(a));
    cout << min(a[n - 2] - a[0], a[n - 1] - a[1]) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}