/*
 * =====================================
 * Author : north_h
 * Time : 2023-08-20 23:11:36
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
    string s1, s2;
    cin >> s1 >> s2;
    //reverse(ALL(s2));
    reverse(ALL(s1));
    string ans = "";
    // cout << s1 << ' ' << s2 << endl;
    int cnt = 0;
    for(auto i : s1) {
        cnt++;
        int x = (i - '0');
        int y = (s2.back() - '0');
        s2.pop_back();
        if(y < x && s2.size()) {
            y = y  + (s2.back() - '0') * 10;
            s2.pop_back();
        }
        // cout << x << ' ' << y << endl;
        if(y - x >= 10 || y - x < 0) {
            cout << -1 << endl;
            return ;
        }
        ans += to_string(y - x);
        if(!s2.size())break;
    }
    while(s2.size())ans += s2.back(), s2.pop_back();
    while(ans.back() == '0' && ans.size())  ans.pop_back();
    reverse(ALL(ans));
    if(s1.size() != cnt)cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}