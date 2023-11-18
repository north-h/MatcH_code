/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-16 19:35:16
 *
 * Problem: A. LuoTianyi and the Palindrome String
 * Contest: Codeforces - Codeforces Round 872 (Div. 2)
 * URL:     https://codeforces.com/contest/1825/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s)mp[i]++;
    if(mp.size() == 1) {
        cout << -1 << endl;
        return ;
    }
    bool ok = true;
    for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if(s[i] != s[j]) {
            ok = false;
            break;
        }
    }
    if(ok)cout << s.size() - 1 << endl;
    else cout << s.size() << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}