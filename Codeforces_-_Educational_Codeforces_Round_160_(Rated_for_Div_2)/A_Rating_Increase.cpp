/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-18 23:46:33
 *
 * Problem: A. Rating Increase
 * Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1913/problem/A
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
const int M = 110;

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0, res = 0;
    bool ok = true;
    for(int i = 0; i < s.size() - 1; i++) {
        if(ok)ans = ans * 10 + (s[i] - '0');
        else res = res * 10 + (s[i] - '0');
        if(s[i + 1] == '0')continue;
        ok = false;
    }
    res = res * 10 + (s.back() - '0');
    if(ans < res)cout << ans << ' ' << res << endl;
    else cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}