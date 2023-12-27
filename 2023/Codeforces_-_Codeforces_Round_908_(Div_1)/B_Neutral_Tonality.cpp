/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-29 18:22:27
 *
 * Problem: B. Neutral Tonality
 * Contest: Codeforces - Codeforces Round 908 (Div. 1)
 * URL:     https://codeforces.com/problemset/problem/1893/B
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    sort(b.rbegin(), b.rend());
    vector<int> ans;
    int now = 0;
    for(int i = 0; i < n; i++) {
        while(now < m && b[now] >= a[i]) {
            // ans.push_back(b[now++]);
            cout << b[now++] << ' ';
        }
        // ans.push_back(a[i]);
        cout << a[i] << ' ';
    }
    while(now < m) {
        // ans.push_back(b[now++]);
        cout << b[now++] << ' ';
    }
    // for(auto i : ans)cout << i << ' ';
    // cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}