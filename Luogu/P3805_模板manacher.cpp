/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-12 16:07:46
 *
 * Problem: P3805 【模板】manacher
 * Contest: Luogu
 * URL:     https://www.luogu.com.cn/problem/P3805
 * MemoryL: 512 MB
 * TimeL:   1000 ms
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
const int N = 11000010;
const int M = 110;

using namespace std;

int d[N];

int Manacher(string s) {
    d[1] = 1;
    for(int i = 2, l, r = 1; i < s.size(); i++) {
        if(i <= r)d[i] = min(d[r + l - i], r - i + 1);
        while(s[i - d[i]] == s[i + d[i]])d[i]++;
        if(i + d[i] - 1 > r)l = i - d[i] + 1, r = i + d[i] - 1;
    }
    int ans = 0;
    for(int i = 1; i < s.size(); i++)ans = max(ans, d[i]);
    return ans;
}

void solve() {
    string s, str;
    cin >> s;
    str = "$#";
    for(auto i : s) {
        str += i;
        str += '#';
    }
    // cout << Manacher(str) - 1 << endl;
    // cout << str << endl;
    // for(int i = 1; i <= str.size(); i++)cout << d[i] << ' ';
    // cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}