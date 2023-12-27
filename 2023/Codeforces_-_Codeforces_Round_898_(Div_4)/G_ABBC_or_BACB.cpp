/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-21 22:36:14
 *
 * Problem: G. ABBC or BACB
 * Contest: Codeforces - Codeforces Round 898 (Div. 4)
 * URL:     https://codeforces.com/contest/1873/problem/G
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
#define lcm(x,y) x*y/__gcd(x,y)
#define debug(a) cout << #a << '=' << a << endl;
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> a, b;
    int cnt = 0;
    for(auto i : s) {
        if(i == 'A')cnt++;
        else {
            if(cnt)a.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt)a.push_back(cnt);
    for(auto i : s) {
        if(i == 'B')b.push_back(1);
    }
    sort(ALL(a));
    int ans = 0;
    for(auto i : a)ans += i;
    if(b.size() == 0 || a.size() == 0)cout << 0 << endl;
    else if(b.size() < a.size())cout << ans - a[0] << endl;
    else cout << ans << endl;
    // debug(ans);
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}