/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-16 20:00:15
 *
 * Problem: B - Pentagon
 * Contest: AtCoder - Toyota Programming Contest 2023#8（AtCoder Beginner Contest 333）
 * URL:     https://atcoder.jp/contests/abc333/tasks/abc333_b
 * MemoryL: 1024 MB
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
    string a, b;
    cin >> a >> b;
    int a1 = a[0] - a[1];
    a1 = abs(a1);
    int a2 = 5 - a1;
    int b1 = b[0] - b[1];
    b1 = abs(b1);
    int b2 = 5 - b1;
    if((a1 == b1 || a1 == b2) && (a2 == b1 || a2 == b2))cout << "Yes" << endl;
    else cout << "No" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}