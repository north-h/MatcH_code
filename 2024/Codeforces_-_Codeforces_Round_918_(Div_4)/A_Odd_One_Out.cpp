/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-01-15 16:49:31
 *
 * Problem: A. Odd One Out
 * Contest: Codeforces - Codeforces Round 918 (Div. 4)
 * URL:     https://codeforces.com/contest/1915/problem/A
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) cout << c << endl;
    else if (a == c) cout << b << endl;
    else cout << a << endl;
    vector<int> a(10 + 1);
    for(int i=0;i<n;i++){

    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}