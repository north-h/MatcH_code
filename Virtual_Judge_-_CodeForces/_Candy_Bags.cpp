/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-23 09:17:38
 *
 * Problem:  Candy Bags
 * Contest: Virtual Judge - CodeForces
 * URL:     https://vjudge.net/problem/CodeForces-334A#author=kg20006
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
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            for(int j = 1; j <= n; j++) {
                a[j][i] = cnt++;
            }
        } else {
            for(int j = n; j >= 1; j--) {
                a[j][i] = cnt++;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}