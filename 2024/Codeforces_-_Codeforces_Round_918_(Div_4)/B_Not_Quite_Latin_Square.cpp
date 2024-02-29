/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-01-15 16:49:35
 *
 * Problem: B. Not Quite Latin Square
 * Contest: Codeforces - Codeforces Round 918 (Div. 4)
 * URL:     https://codeforces.com/contest/1915/problem/B
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
    map<char, int> mp;
    for(int i = 1; i <= 3; i++) {
        string s;
        cin >> s;
        for(auto j : s)mp[j]++;
    }
    for(auto [x, y] : mp) {
        if(y == 2) {
            cout << x << endl;
            return ;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}