/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-19 16:04:05
 *
 * Problem: 最长上升子序列 II
 * Contest: AcWing
 * URL:     https://www.acwing.com/problem/content/898/
 * MemoryL: 64 MB
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
const int N = 100010;
const int M = 110;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for(auto &i : a)cin >> i;
    for(auto i : a) {
        if(!b.size() || i > b.back())b.push_back(i);
        else {
            int pos = lower_bound(b.begin(), b.end(), i) - b.begin();
            b[pos] = i;
        }
    }
    cout << b.size() << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}