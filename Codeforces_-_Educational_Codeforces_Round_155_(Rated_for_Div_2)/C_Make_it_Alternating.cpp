/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-24 22:35:32
 *
 * Problem: C. Make it Alternating
 * Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1879/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 200010;
const int M = 1910;
const int P = 998244353;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 1;
    ll ans = 0;
    ll res = 0;
    ll aes = 0;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1])cnt++;
        else {
            if(cnt > 1)aes++;
            res += cnt - 1;
            if(cnt > 1)ans *= cnt * (cnt - 1);
            ans %= P;
            cnt = 1;
        }
    }
    res += cnt - 1;
    if(cnt > 1)ans *= cnt * (cnt - 1);
    ans %= P;
    if(res == 0)ans = 1;
    // if(aes > 1)ans *= (aes - 1) * aes;
    // ans %= P;
    cout << res << ' ' << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}