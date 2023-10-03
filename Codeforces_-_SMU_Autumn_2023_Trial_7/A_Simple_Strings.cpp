/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-03 11:15:15
 *
 * Problem: A. Simple Strings
 * Contest: Codeforces - SMU Autumn 2023 Trial 7
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475593/problem/A
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
    string s;
    cin >> s;
    vector<PII> a;
    int r = 0;
    int cnt = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) {
            cnt++;
            r = i;
        } else {
            if(cnt > 1)a.push_back({r - cnt + 1, r});
            cnt = 1;
        }
    }
    if(cnt)a.push_back({r - cnt + 1, r});
    for(auto [x, y] : a) {
        char op = s[x];
        // cout << x << ' ' << y << endl;
        // debug1(op);
        int len = y - x + 1;
        if(len & 1) {
            if(op == 'z')op = 'a';
            else op++;
            for(int i = x + 1; i <= y; i += 2) {
                // debug2(i, s[i]);
                s[i] = op;
            }
        } else {
            if(x != 0)op = s[x - 1];
            if(op == 'z')op = 'a';
            else op++;
            while(op == s[x]) {
                op++;
                if(op > 'z')op = 'a';
            }
            for(int i = x; i <= y; i += 2) {
                s[i] = op;
            }
        }
    }
    cout << s << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}