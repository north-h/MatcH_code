/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-13 19:01:03
 *
 * Problem: J. Find the cat
 * Contest: Codeforces - October come back. Together training
 * URL:     https://codeforces.com/gym/104678/problem/J
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
    int n = s.size();
    s = " " + s;
    int x = -1, y = -1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'c') {
            x = i;
            break;
        }
    }
    for(int i = x + 1; i < s.size(); i++) {
        if(s[i] == 'a') {
            y = i;
            break;
        }
    }
    // debug2(x, y);
    if(x != -1 && y != -1 && y < n) {
        cout << x << ' ' << y << ' ' << y + 1 << endl;
        return ;
    }
    x = -1, y = -1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 't') {
            y = max(i, y);
        }
    }
    for(int i = y - 1; i >= 1; i--) {
        if(s[i] == 'a') {
            x = i;
            break;
        }
    }
    // debug2(x, y);
    if(x != -1 && y != -1 && x > 1) {
        cout << x - 1 << ' ' << x << ' ' << y << endl;
        return ;
    }
    x = -1, y = -1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'c') {
            x = i;
            break;
        }
    }
    for(int i = x + 1; i < s.size(); i++) {
        if(s[i] == 't') {
            y = max(y, i);
        }
    }
    // debug2(x, y);
    if(x != -1 && y != -1 && abs(x - y) != 1) {
        cout << x << ' ' << y - 1 << ' ' << y << endl;
        return ;
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}