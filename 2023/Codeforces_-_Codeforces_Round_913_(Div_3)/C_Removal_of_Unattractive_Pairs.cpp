/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:39
 *
 * Problem: C. Removal of Unattractive Pairs
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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
    string s;
    cin >> n >> s;
    map<char, int> mp;
    for(auto i : s)mp[i]++;
    int ans = 0;
    int mx = 0;
    vector<int> b;
    for(auto [x, y] : mp) {
        mx = max(y, mx);
    }
    if(mx > n / 2)cout << 2 * mx - n << endl;
    else if(n & 1)cout << 1 << endl;
    else cout << 0 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}