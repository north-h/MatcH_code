/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:34
 *
 * Problem: A. Rook
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/A
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
    string s;
    cin >> s;
    for(int i = 1; i <= 8; i++) {
        if(i != s[1] - '0')cout << s[0] << i << endl;
    }
    for(char i = 'a'; i <= 'h'; i++) {
        if(i != s[0])cout << i << s[1] << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}