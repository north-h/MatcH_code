/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-10 00:07:15
 *
 * Problem: B. Collecting Game
 * Contest: Codeforces - Codeforces Round 914 (Div. 2)
 * URL:     https://codeforces.com/contest/1904/problem/B
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
    vector<PII> a(n + 1), dp(n + 1);
    vector<ll>s(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i].fi;
    }
    dp[n].fi = a[n].se;
    dp[n].se = n - 1;
    for(int i = n - 1; i >= 1; i--) {
        dp[i].fi = a[i].se;
        if(s[i] >= a[i + 1].fi) {
            dp[i].se = dp[i + 1].se;
        } else {
            dp[i].se = i - 1;
        }
    }
    sort(dp.begin() + 1, dp.end());
    for(int i = 1; i <= n; i++)cout << dp[i].se << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}