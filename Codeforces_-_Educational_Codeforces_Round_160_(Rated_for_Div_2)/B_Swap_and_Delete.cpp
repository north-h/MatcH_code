/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-18 23:46:37
 *
 * Problem: B. Swap and Delete
 * Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1913/problem/B
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
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s) {
        mp[i]++;
    }
    int ans = 0;
    string sans;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            if(mp['0'] > 0)mp['0']--, sans += '0';
            else mp['1']--, sans += '1', ans++;
        } else {
            if(mp['1'] > 0)mp['1']--, sans += '1';
            else mp['0']--, sans += '0', ans++;
        }
    }
    for(int i = 0, j = 0; i < s.size() && j < sans.size();) {
        if(s[i] != sans[j]) {
            i++;
            j++;
        } else {
            j++;
            ans++;
        }
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