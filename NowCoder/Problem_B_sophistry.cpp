/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-12 20:39:12
 *
 * Problem: Problem B. sophistry
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/22754/B
 * MemoryL: 524288 MB
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
    int n, d, m;
    cin >> n >> d >> m;;
    vector<ll> a(n + 1), dp(n + 2);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = n; i >= 1; i--) {
        if(a[i] > m) {
            dp[i] = max(dp[i + 1], dp[min(i + d + 1, n + 1)] + a[i]);
        } else dp[i] = dp[i + 1] + a[i];
    }
    cout << dp[1] << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}