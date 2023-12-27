/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-19 16:14:35
 *
 * Problem: 参加算法竞赛！
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/72143/E
 * MemoryL: 524288 MB
 * TimeL:   2000 ms
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
    int n;
    cin >> n;
    vector<int> a(n + 1), dp1(n + 1), dp2(n + 1), dp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(!dp.size() || a[i] > dp.back())dp.push_back(a[i]);
        else {
            int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[pos] = a[i];
        }
        dp1[i] = dp.size();
    }
    dp.clear();
    for(int i = n; i >= 1; i--) {
        if(!dp.size() || a[i] < dp.back())dp.push_back(a[i]);
        else {
            int pos = lower_bound(dp.begin(), dp.end(), a[i], greater<int>()) - dp.begin();
            dp[pos] = a[i];
        }
        dp2[i] = dp.size();
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i] + dp2[i]);
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}