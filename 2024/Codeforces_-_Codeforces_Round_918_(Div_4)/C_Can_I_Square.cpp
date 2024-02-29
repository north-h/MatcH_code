/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-01-15 16:49:40
 *
 * Problem: C. Can I Square?
 * Contest: Codeforces - Codeforces Round 918 (Div. 4)
 * URL:     https://codeforces.com/contest/1915/problem/C
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
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        sum += x;
    }
    if((ll)sqrt(sum) * (ll)sqrt(sum) == sum)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}