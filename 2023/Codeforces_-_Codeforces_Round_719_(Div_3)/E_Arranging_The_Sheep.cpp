/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-14 15:05:32
 *
 * Problem: E. Arranging The Sheep
 * Contest: Codeforces - Codeforces Round 719 (Div. 3)
 * URL:     https://codeforces.com/contest/1520/problem/E
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
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    s = " " + s;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '*')pos.push_back(i);
    }
    int res = pos.size() / 2;
    int ans = 0;
    for(int i = res - 1, l = 1; i >= 0; i--, l++)ans += pos[res] - pos[i] - l;
    for(int i = res + 1, l = 1; i < pos.size(); i++, l++)ans += pos[i] - pos[res] - l;
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}