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

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i <= 30; i++) {
        int x = 0;
        int cnt[2] = {0, 0};
        int sum[2] = {0, 0};
        int res = 0;
        for(int j = 0; j <= n; j++) {
            x ^= ((a[j] >> i) & 1);
            res = (res + (cnt[!x] * j - sum[!x]) % mod) % mod;
            cnt[x] = (cnt[x] + 1) % mod;;
            sum[x] = (sum[x] + j) % mod;
        }
        ans = (ans + (res * (1ll << i)) % mod) % mod;
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