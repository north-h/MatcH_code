/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-22 12:55:31
 * =====================================
 * Thirty years east, thirty years west,
 * don't you dare bully me because I'm poor now.
 *                  _   _         _
 * _ __   ___  _ __| |_| |__     | |__
 *| '_ \ / _ \| '__| __| '_ \    | '_ \
 *| | | | (_) | |  | |_| | | |   | | | |
 *|_| |_|\___/|_|   \__|_| |_|___|_| |_|
 *                          |_____|
 */

#pragma GCC optimize(3)

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
#define rALL(a) a.begin(),a.end()
#define int128 __int128
#define endl '\n'
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const int EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    map<string, int> mp;
    map<char, int> pos0, pos1;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
        pos0[s[0]]++;
        pos1[s[1]]++;
    }
    int ans = 0;
    int res = 0;
    for(auto [x, y] : mp) {
        res += y * (y - 1) / 2;
    }
    res *= 2;
    for(auto [x, y] : pos0) {
        ans += y * (y - 1) / 2;
    }
    for(auto [x, y] : pos1) {
        ans += y * (y - 1) / 2;
    }
    cout << ans - res << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}