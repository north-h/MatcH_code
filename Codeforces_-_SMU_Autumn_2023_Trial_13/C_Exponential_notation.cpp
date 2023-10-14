/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-09 13:45:21
 *
 * Problem: C. Exponential notation
 * Contest: Codeforces - SMU Autumn 2023 Trial 13
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/475604/problem/C
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
    bool ok = true;
    for(auto i : s) {
        if(i == '.') {
            ok = false;
            break;
        }
    }
    if(!ok)while(s.back() == '0')s.pop_back();
    reverse(ALL(s));
    while(s.back() == '0')s.pop_back();
    reverse(ALL(s));
    // debug2(s, ok);
    if(s[0] == '.') {
        int pos;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != '0') {
                pos = i;
                break;
            }
        }
        string s1 = s.substr(pos, 1) + '.' + s.substr(pos + 1);
        while(s1.back() == '0')s1.pop_back();
        if(s1.back() == '.')s1.pop_back();
        cout << s1 << 'E' << -pos << endl;
    } else {
        if(ok)s += '.';
        int pos;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '.') {
                pos = i;
                break;
            }
        }
        string s1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '.')s1 += s[i];
        }
        string s2 = s1.substr(0, 1) + '.' + s1.substr(1);
        while(s2.back() == '0')s2.pop_back();
        if(s2.back() == '.')s2.pop_back();
        if(pos - 1 == 0)cout << s2 << endl;
        else cout << s2 << 'E' << pos - 1 << endl;
    }
}
int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}