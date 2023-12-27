/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-10 00:07:12
 *
 * Problem: A. Forked!
 * Contest: Codeforces - Codeforces Round 914 (Div. 2)
 * URL:     https://codeforces.com/contest/1904/problem/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    map<PII, int> mp;
    int dx[8] = {a, a, -a, -a, b, b, -b, -b};
    int dy[8] = {b, -b, b, -b, a, -a, a, -a};
    int cnt = 8;
    if(a == b)cnt = 4;
    for(int i = 0; i < cnt; i++) {
        int x = dx[i] + xk;
        int y = dy[i] + yk;
        mp[ {x, y}]++;
    }
    for(int i = 0; i < cnt; i++) {
        int x = dx[i] + xq;
        int y = dy[i] + yq;
        mp[ {x, y}]++;
    }
    int ans = 0;
    for(auto [x, y] : mp) {
        if(y >= 2)ans++;
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}