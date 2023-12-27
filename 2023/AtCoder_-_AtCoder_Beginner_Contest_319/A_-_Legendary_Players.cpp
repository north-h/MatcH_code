/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-10 10:26:13
 *
 * Problem: A - Legendary Players
 * Contest: AtCoder - AtCoder Beginner Contest 319
 * URL:     https://atcoder.jp/contests/abc319/tasks/abc319_a
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    map<string, int> mp;
    mp["tourist"] = 3858;
    mp["ksun48"] = 3679 ;
    mp["Benq"] = 3658  ;
    mp["Um_nik"] = 3648  ;
    mp["apiad"] = 3638  ;
    mp["Stonefeang"] = 3630 ;
    mp["ecnerwala"] = 3613  ;
    mp["mnbvmar"] = 3555     ;
    mp["newbiedmy"] = 3516 ;
    mp["semiexp"] = 3481   ;
    string s;
    cin >> s;
    cout << mp[s] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}