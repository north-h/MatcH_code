/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-12 08:47:18
 *
 * Problem: B. XOR Palindromes
 * Contest: Codeforces - Codeforces Round 897 (Div. 2)
 * URL:     https://codeforces.com/contest/1867/problem/B
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
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0, j = n - 1; i < j; i++, j--) {
        if(s[i] != s[j])ans++;
    }
    string sans;
    for(int i = 0; i <= n; i++) {
        if(i < ans || i > n - ans)sans += '0';
        else sans += '1';
    }
    if(n & 1 && ans != 0) {
        for(int i = 0; i < n; i++) {
            if(sans[i] == '1')sans[i + 1] = '0';
        }
    }
    cout << sans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}