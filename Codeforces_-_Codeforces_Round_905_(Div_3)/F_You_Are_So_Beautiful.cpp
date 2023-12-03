/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-03 14:03:59
 *
 * Problem: F. You Are So Beautiful
 * Contest: Codeforces - Codeforces Round 905 (Div. 3)
 * URL:     https://codeforces.com/problemset/problem/1883/F
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return x;
    }
    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); // 时间戳
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    unordered_map<int, int, custom_hash> mp;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        mp[a[i]]++;
        if(mp[a[i]] == 1)dp[i] = 1, cnt++;
        else dp[i] = 0;
    }
    mp.clear();
    ll ans = 0;
    for(int i = n; i >= 1; i--) {
        mp[a[i]]++;
        if(mp[a[i]] == 1)ans += cnt;
        if(dp[i])cnt--;
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