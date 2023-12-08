/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-08 13:33:48
 *
 * Problem: A. Fill in the Matrix
 * Contest: Codeforces - Codeforces Round 896 (Div. 1)
 * URL:     https://codeforces.com/problemset/problem/1868/A
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    if(m == 1) {
        cout << 0 << endl;
        for(int i = 0; i < n; i++)cout << 0 << endl;
        return ;
    }
    if(n == 1) {
        cout << 2 << endl;
        for(int i = 0; i < m; i++)cout << i << ' ';
        cout << endl;
        return ;
    }
    if(n >= m) {
        cout << m << endl;
        for(int i = 1, s = 1; i < m; i++, s++) {
            for(int j = 1, k = s; j <= m; j++, k++) {
                if(k == m)k = 0;
                cout << k << ' ';
            }
            cout << endl;
        }
        for(int i = m, s = m - 1; i <= n; i++) {
            for(int j = 1, k = s; j <= m; j++, k++) {
                if(k == m)k = 0;
                cout << k << ' ';
            }
            cout << endl;
        }
    } else {
        cout << n + 1 << endl;
        for(int i = 1, s = 0; i <= n; i++, s++) {
            for(int j = 1, k = s; j <= n + 1; j++, k++) {
                if(k == n + 1)k = 0;
                cout << k << ' ';
            }
            for(int j = n + 2, k = n + 1; j <= m; j++, k++) {
                cout << k << ' ';
            }
            cout << endl;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}