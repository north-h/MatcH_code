/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-24 22:35:36
 *
 * Problem: D. Sum of XOR Functions
 * Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1879/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 10010;
const int M = 1910;
const int mod = 998244353;

using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int t = 0; t <= 0; t++) {
        for (int i = 1; i <= n; i++) {
            b[i] = (a[i] >> t) & 1;
            cout << b[i];
        }
        cout << endl;
        int x = 0, res = 0;   // the number of 1s
        int cnt[2] = {1, 0};  // the number of the intervals
        int sum[2] = {0, 0};  // the sum of the intervals' lengthes
        for (int i = 1; i <= n; i++) {
            x = (x + b[i]) % 2;
            debug2(x, 1 - x);
            res = (res + (ll)cnt[1 - x] * i % mod - sum[1 - x] + mod) % mod;
            cnt[x]++, sum[x] = (sum[x] + i) % mod;
            debug2(cnt[0], cnt[1]);
            debug2(sum[0], sum[1]);
        }
        ans = (ans + (ll)res * ((1 << t) % mod) % mod) % mod;
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