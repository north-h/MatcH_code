/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-19 21:53:31
 *
 * Problem: F. Game of Stacks
 * Contest: Codeforces - Codeforces Round 906 (Div. 2)
 * URL:     https://codeforces.com/contest/1890/problem/F
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

PII check(string s) {
    for(int i = 0, j = s.size() - 1; i <= j; i++, j--) {
        if(s[i] == s[j]) {
            return {s[i] - '0', i};
        }
    }
    return {-1, -1};
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // if(s.size() & 1) {
    //     cout << -1 << endl;
    //     return ;
    // }
    vector<int> ans;
    for(int i = 1; i <= 300; i++) {
        auto t = check(s);
        //        debug2(t.fi,t.se);
        if(t.fi == -1 && t.se == -1) {
            cout << ans.size() << endl;
            for(auto j : ans)cout << j + 1 << ' ';
            cout << endl;
            return ;
        } else if(t.fi == 1) {
            s = s.substr(0, t.se) + "01" + s.substr(t.se);
            if(t.se == 0)ans.push_back(t.se - 1);
            else ans.push_back(t.fi);
        } else {
            int pos = s.size() - 1 - t.se;
            s = s.substr(0, pos + 1) + "01" + s.substr(pos + 1);
            ans.push_back(pos);
        }
        // debug1(s);
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}