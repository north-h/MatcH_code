/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-01 00:32:58
 *
 * Problem: A. Anonymous Informant
 * Contest: Codeforces - Codeforces Round 908 (Div. 1)
 * URL:     https://codeforces.com/contest/1893/problem/A
 * MemoryL: 512 MB
 * TimeL:   3000 ms
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
    vector<int> vis(n + 1);
    int now = n;
    for(int i = 1; i <= k; i++) {
        if(a[now] > n) {
            cout << "No" << endl;
            return ;
        }
        if(vis[i])break;
        now -= a[now];
        now = (now + n) % n;
    }
    cout << "Yes" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}