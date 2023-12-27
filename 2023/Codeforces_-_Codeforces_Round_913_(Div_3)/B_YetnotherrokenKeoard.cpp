/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:38
 *
 * Problem: B. YetnotherrokenKeoard
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/B
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
    vector<int> da, xiao;
    vector<int> vis(s.size() + 1);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'b' && xiao.size()) {
            vis[xiao.back()] = 1;
            xiao.pop_back();
        } else if(s[i] == 'B' && da.size()) {
            vis[da.back()] = 1;
            da.pop_back();
        } else if(s[i] >= 'a' && s[i] <= 'z')xiao.push_back(i);
        else da.push_back(i);
    }
    for(int i = 0; i < s.size(); i++) {
        if(!vis[i] && s[i] != 'B' && s[i] != 'b')cout << s[i];
    }

    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}