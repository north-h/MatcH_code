/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 19:04:31
 *
 * Problem: Kevin逛超市 2 (简单版本)
 * Contest: NowCoder
 * URL:     https://ac.nowcoder.com/acm/contest/70845/B
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
const int M = 110;

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    int mx = 0;
    for(auto &i : a) {
        cin >> i;
        sum += i;
    }
    sort(a.begin(), a.end());
    if(n == 1)cout << lf(12) << min(a[0]*x * 1.0 / 100, max(0, a[0] - y) * 1.0);
    else {
        double c = sum - a[n - 1] - a[n - 2] + a[n - 1] * x * 1.0 / 100 + max(0.0, (a[n - 2] - y) * 1.0);
        double b = sum - a[n - 2] - a[n - 1] + a[n - 2] * x * 1.0 / 100 + max(0.0, (a[n - 1] - y) * 1.0);
        cout << lf(12) << min(c, b) << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}