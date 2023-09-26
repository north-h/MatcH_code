/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-26 15:11:07
 *
 * Problem: A. Everyone Loves to Sleep
 * Contest: Codeforces - SMU Autumn 2023 Round 5
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475398/problem/A
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, H, M;
    cin >> n >> H >> M;
    vector<int> a;
    for(int i = 1; i <= n; i++) {
        int h, m;
        cin >> h >> m;
        int x = h * 60 + m;
        a.push_back(x);
    }
    sort(ALL(a));
    int res = H * 60 + M;
    for(auto i : a) {
        if(i >= res) {
            cout << (i - res) / 60 << ' ' << (i - res) % 60 << endl;
            return ;
        }
    }
    cout << (24 * 60 - res + a[0] ) / 60 << ' ' << (24 * 60 - res + a[0] ) % 60 << endl;

}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}