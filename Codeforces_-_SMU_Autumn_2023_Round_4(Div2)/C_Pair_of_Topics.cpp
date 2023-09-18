/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-16 22:16:20
 *
 * Problem: C. Pair of Topics
 * Contest: Codeforces - SMU Autumn 2023 Round 4(Div.2)
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/473587/problem/C
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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug(a,b) cout << (steing)a << '=' << b << endl;
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d;
    map<int, int> mp;
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    for(int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
        cout << c[i] << ' ';
    }
    cout << endl;
    d = c;
    sort(ALL(d));
    for(int i = 0; i < n; i++) {
        cout << d[i] << ' ';
        mp[d[i]] = i;
    }
    cout << endl;
    ll ans = 0;
    bool ok = true;
    for(auto [x, y] : mp)cout << x << ' ' << y << endl;
    for(int i = 0; i < n; i++) {
        ans += mp[c[i]] - 1;
        cout << mp[c[i]] << ' ';
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