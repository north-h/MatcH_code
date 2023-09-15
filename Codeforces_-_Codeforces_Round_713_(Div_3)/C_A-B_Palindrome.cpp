/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-15 13:25:23
 *
 * Problem: C. A-B Palindrome
 * Contest: Codeforces - Codeforces Round 713 (Div. 3)
 * URL:     https://codeforces.com/contest/1512/problem/C
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
#define debug(a, b) cout<<(string)a<<'='<<b<<endl;
const int N = 10010;
const int M = 1910;
const int MOD = 98244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    for(auto i : s) {
        if(i == '0')a--;
        if(i == '1')b--;
    }
    for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if(s[i] == '?' && s[j] != '?') {
            if(s[j] == '0')a--;
            else b--;
            s[i] = s[j];
        } else if(s[j] == '?' && s[i] != '?') {
            if(s[i] == '0')a--;
            else b--;
            s[j] = s[i];
        } else if(s[i] != s[j]) {
            cout << -1 << endl;
            return ;
        }
    }
    for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if(s[i] == '?' && s[j] == '?') {
            if(a >= 2)s[i] = s[j] = '0', a -= 2;
            else if(b >= 2)s[i] = s[j] = '1', b -= 2;
        }
    }
    if(s.size() & 1 && s[s.size() / 2] == '?') {
        char op;
        if(a >= 1)op = '0', a--;
        else if(b >= 1)op = '1', b--;
        // debug("op", op);
        s[s.size() / 2] = op;
    }
    // cout << a << ' ' << b << endl;
    if(a != 0 || b != 0)cout << -1 << endl;
    else cout << s << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}