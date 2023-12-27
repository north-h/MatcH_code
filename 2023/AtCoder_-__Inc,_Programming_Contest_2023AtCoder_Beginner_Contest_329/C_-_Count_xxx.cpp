/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-18 20:02:29
 *
 * Problem: C - Count xxx
 * Contest: AtCoder - Ｓｋｙ Inc, Programming Contest 2023（AtCoder Beginner Contest 329）
 * URL:     https://atcoder.jp/contests/abc329/tasks/abc329_c
 * MemoryL: 1024 MB
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
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    int cnt = 1;
    ll ans = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1])cnt++;
        else {
            // debug2(s[i - 1], cnt);
            if(!mp.count(s[i - 1])) {
                ans += cnt;
                mp[s[i - 1]] = cnt;
            } else {
                if(mp[s[i - 1]] < cnt) {
                    ans += cnt - mp[s[i - 1]];
                    mp[s[i - 1]] = cnt;
                }
            }
            cnt = 1;
        }
    }
    // for(auto [x, y] : mp)cout << x << ' ' << y << endl;
    if(!mp.count(s.back())) {
        ans += cnt;
        mp[s.back()] = cnt;
    } else {
        if(mp[s.back()] < cnt) {
            // debug2(mp[s.back()], cnt);
            ans += cnt - mp[s.back()];
            mp[s.back()] = cnt;
        }
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