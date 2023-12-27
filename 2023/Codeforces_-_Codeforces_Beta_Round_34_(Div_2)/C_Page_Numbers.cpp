/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-04 17:30:27
 *
 * Problem: C. Page Numbers
 * Contest: Codeforces - Codeforces Beta Round 34 (Div. 2)
 * URL:     https://codeforces.com/contest/34/problem/C
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
    vector<int> a;
    string s;
    cin >> s;
    int num = 0;
    for(auto i : s) {
        if(i >= '0' && i <= '9')num = num * 10 + i - '0';
        else a.push_back(num), num = 0;
    }
    if(num)a.push_back(num);
    sort(ALL(a));
    a.erase(unique(ALL(a)), a.end());
    // for(auto i : a)cout << i << " ";
    // cout << endl;
    int l = 0, r = 0;
    for(int i = 1; i < a.size(); i++) {
        if(a[i] == a[i - 1] + 1)r = i;
        else {
            if(l == r)cout << a[l], l++, r++;
            else cout << a[l] << '-' << a[r], r++, l = r;
            if(i < a.size())cout << ',';
            else cout << endl;
        }
    }
    if(l == r)cout << a[l];
    else cout << a[l] << '-' << a[r];
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}