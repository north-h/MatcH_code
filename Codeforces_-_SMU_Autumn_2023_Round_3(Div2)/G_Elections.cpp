/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-13 16:09:54
 *
 * Problem: G. Elections
 * Contest: Codeforces - SMU Autumn 2023 Round 3(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/470094/problem/G
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
    vector<PII> a(3);
    cin >> a[0].se >> a[1].se >> a[2].se;
    a[0].fi = 0;
    a[1].fi = 1;
    a[2].fi = 2;
    sort(ALL(a), [](PII x, PII y) {
        return x.se < y.se;
    });
    // cout << a[0].se << ' ' << a[1].se << ' ' << a[2].se << endl;
    // cout << a[0].fi << ' ' << a[1].fi << ' ' << a[2].fi << endl;
    bool ok = true;
    if(a[0].se == a[2].se)a[0].se = 1, ok = false;
    else a[0].se = a[2].se - a[0].se + 1;
    if(a[1].se == a[2].se)a[1].se = 1, ok = false;
    else a[1].se = a[2].se - a[1].se + 1;
    if(!ok)a[2].se = 1;
    else a[2].se = 0;
    sort(ALL(a));
    cout << a[0].se << ' ' << a[1].se << ' ' << a[2].se << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}