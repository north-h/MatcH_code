/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-07 23:47:31
 *
 * Problem: B. Effects of Anti Pimples
 * Contest: Codeforces - Codeforces Round 902 (Div. 1, based on COMPFEST 15 - Final Round)
 * URL:     https://codeforces.com/problemset/problem/1876/B
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
const int P = 998244353;

using namespace std;

ll ksm(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1)res *= a, res %= P;
        b >>= 1;
        a = a * a;
        a %= P;
    }
    return res % P;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ )
        for(int j = i; j <= n; j += i)
            a[i] = max(a[i], a[j]);
    sort(a.begin() + 1, a.end(), greater<int>());
    ll ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        (ans += a[i] * ksm(2, n - i)) %= P;
    }
    cout << ans;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}