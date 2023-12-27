/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-19 22:56:20
 *
 * Problem: C. Quests
 * Contest: Codeforces - Codeforces Round 916 (Div. 3)
 * URL:     https://codeforces.com/contest/1914/problem/C
 * MemoryL: 256 MB
 * TimeL:   2500 ms
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    int res = 0;
    int mx = 0;
    int ans = 0;
    for(int i = 1; i <= n && i <= k; i++) {
        res += a[i];
        mx = max(mx, b[i]);
        ans = max(ans, res + (k - i) * mx);
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