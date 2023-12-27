/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-22 13:20:47
 *
 * Problem: A. Casimir's String Solitaire
 * Contest: Codeforces - Codeforces Round 744 (Div. 3)
 * URL:     https://codeforces.com/contest/1579/problem/A
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
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s)mp[i]++;
    vector<int> a;
    for(auto [x, y] : mp) {
        a.push_back(y);
    }
    if(mp['A'] > mp['B'] || mp['C'] > mp['B'])cout << "NO" << endl;
    else {
        int ans = mp['B'] - mp['A'];
        if(ans == mp['C'])cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}