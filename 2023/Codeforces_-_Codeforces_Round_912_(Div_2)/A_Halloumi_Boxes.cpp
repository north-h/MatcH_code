/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 00:40:04
 *
 * Problem: A. Halloumi Boxes
 * Contest: Codeforces - Codeforces Round 912 (Div. 2)
 * URL:     https://codeforces.com/contest/1903/problem/A
 * MemoryL: 256 MB
 * TimeL:   1000 ms
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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(is_sorted(a.begin() + 1, a.end())) {
        cout << "YES" << endl;
        return ;
    }
    if(k == 1)cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}