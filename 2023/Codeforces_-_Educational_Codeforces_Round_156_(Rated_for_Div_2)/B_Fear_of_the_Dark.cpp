/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-10 01:14:30
 *
 * Problem: B. Fear of the Dark
 * Contest: Codeforces - Educational Codeforces Round 156 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1886/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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

double get(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double d1 = get(0, 0, ax, ay);
    double d2 = get(px, py, ax, ay);
    double d3 = get(0, 0, bx, by);
    double d4 = get(px, py, bx, by);
    double ans = min(max(d1, d2), max(d3, d4));
    double d5 = get(ax, ay, bx, by) / 2;
    if(max(d2, d3) >= d5)ans = min(ans, max(d2, d3));
    if(max(d1, d4) >= d5)ans = min(ans, max(d1, d4));
    if(d5 >= d1 && d5 >= d4 || d5 >= d2 && d5 >= d3) {
        ans = min(ans, d5);
    }
    cout << lf(10) << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}