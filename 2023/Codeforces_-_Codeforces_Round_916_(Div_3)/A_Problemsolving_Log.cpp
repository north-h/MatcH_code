/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-19 22:56:15
 *
 * Problem: A. Problemsolving Log
 * Contest: Codeforces - Codeforces Round 916 (Div. 3)
 * URL:     https://codeforces.com/contest/1914/problem/A
 * MemoryL: 256 MB
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
    int n;
    cin >> n;
    map<char, int> mp;
    char op;
    for(int i = 1, op = 'A'; i <= 26; i++, op++) {
        mp[op] = i;
    }
    string s;
    cin >> s;
    map<char, int> up;
    for(auto i : s) {
        up[i]++;
    }
    int ans = 0;
    for(auto [x, y] : up) {
        ans += (y >= mp[x]);
    }
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}