/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-25 22:35:43
 *
 * Problem: C. Card Game
 * Contest: Codeforces - Codeforces Round 899 (Div. 2)
 * URL:     https://codeforces.com/contest/1882/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define endl '\n'
#define debug(a) cout << #a << '=' << a << endl;
#define lf(x)   fixed << setprecision(x)
const double PI = 3.1415926;
const int N = 10010;
const int M = 1910;

using namespace std;

void solve() {
    int  n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(auto &i : a) {
        cin >> i;
        if(i >= 0)sum += i;
    }
    // debug(sum);
    if(a[0] >= 0 || a[0] <= 0 && a[1] <= 0)cout << sum << endl;
    else if(n == 1)cout << max(0, a[0]) << endl;
    else cout << max(sum + a[0], sum - a[1]) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}