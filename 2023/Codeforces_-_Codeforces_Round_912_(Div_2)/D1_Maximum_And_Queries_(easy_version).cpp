/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 00:40:16
 *
 * Problem: D1. Maximum And Queries (easy version)
 * Contest: Codeforces - Codeforces Round 912 (Div. 2)
 * URL:     https://codeforces.com/contest/1903/problem/D1
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    while(q--) {
        int k;
        cin >> k;
        vector<int> b = a;
        int ans = 0;
        for(int i = 60; i >= 0; i--) {
            int sum = 0;
            for(auto j : b) {
                int res = (j >> i) & 1;
                if(res == 0) {
                    sum += (1ll << i) - (j & ((1ll << i) - 1));
                    if(sum > k)break;
                }
            }
            // debug1(sum);
            if(sum <= k) {
                k -= sum;
                ans += (1ll << i);
                // debug1(ans);
                for(auto &j : b) {
                    if(!((j >> i) & 1))j = (1ll << i);
                }
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}