/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-01-12 23:00:45
 *
 * Problem: 抽奖黑幕
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/73202/A
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
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0, mn = INF, mx = 0;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
        sum += x;
    }
    int a = sum - mx;
    int b = sum - mn;
    if(a <= b)cout << mx << endl;
    else cout << mn << endl;
}

int32_t main() {
    // IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}