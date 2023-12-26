/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-26 13:30:31
 *
 * Problem: B. Stock Arbitraging
 * Contest: Codeforces - SMU Autumn 2023 Round 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/494765/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define PI acos(-1)
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 100010;
const int M = 110;

using namespace std;

void solve() {
    int  n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = max(k % a[0] + k / a[0] * b.back(), k);
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}