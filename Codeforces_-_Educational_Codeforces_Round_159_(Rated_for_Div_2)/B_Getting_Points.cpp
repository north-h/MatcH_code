/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-03 22:35:21
 *
 * Problem: B. Getting Points
 * Contest: Codeforces - Educational Codeforces Round 159 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1902/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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
    int n, P, l, t;
    cin >> n >> P >> l >> t;
    int x = (n + 6) / 7;
    // debug1(x);
    int s = (x / 2) * (l + t * 2);
    int ss = s + (x % 2) * (l + t);
    int d = (l + t * 2);
    if(s >= P)cout << n - (P + d - 1) / d << endl;
    else if(ss >= P)cout << n - (x + 1) / 2 << endl;
    else {
        P -= ss;
        int ans = (x + 1) / 2 + (P + l - 1) / l;
        cout << n - ans << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}