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
    for(int i = 0; i < m; i++)a[0].push_back(i);
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
    int x = min(n, m);
    for(int i = 1, k = 1; i < x; i++, k++) {
        if(k == x )k = 0;
        for(int j = 1, s = k; j <= x; j++) {
            a[i].push_back(s++);
            if(s == x)s = 0;
        }
    }
    for(int j = 0; j < x; j++)a[x].push_back(a[x - 1][j]);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    if(n > m) {
        for(int i = m + 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                a[i].push_back(a[i - 1][j]);
            }
        }
    } else if(n < m) {
        for(int i = 1; i <= n; i++) {
            for(int j = n; j < m; j++) {
                a[i].push_back(a[i - 1][j]);
            }
        }
    }
    cout << min(n, m) << endl;
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j < a[i].size(); j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}