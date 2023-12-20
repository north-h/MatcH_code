/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-19 22:56:24
 *
 * Problem: E2. Game with Marbles (Hard Version)
 * Contest: Codeforces - Codeforces Round 916 (Div. 3)
 * URL:     https://codeforces.com/contest/1914/problem/E2
 * MemoryL: 256 MB
 * TimeL:   3500 ms
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<PII> c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        c[i].fi = a[i] + b[i];
        c[i].se = i;
    }
    sort(c.rbegin(), c.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0)ans += a[c[i].se] - 1;
        else ans -= b[c[i].se] - 1;
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