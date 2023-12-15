/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-15 22:30:06
 *
 * Problem: 小天的金银铜铁
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/72041/A
 * MemoryL: 262144 MB
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
    int a, b, c, d, e, A, B, C, D;
    cin >> a >> b >> c >> d >> e >> A >> B >> C >> D;
    ll ans = a * A + b * B + c * C - d * D;
    if(ans >= e)cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}