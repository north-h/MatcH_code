/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-07 16:07:10
 *
 * Problem: C. Joyboard
 * Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
 * URL:     https://codeforces.com/problemset/problem/1877/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 110;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 1)cout << 1 << endl;
    else if(k == 2) {
        if(m <= n)cout << m << endl;
        else cout <<  n + (m - n) / n << endl;
    } else if(k == 3) {
        if(m <= n)cout << 0 << endl;
        else cout << m - n - (m - n) / n << endl;
    } else cout << 0 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}