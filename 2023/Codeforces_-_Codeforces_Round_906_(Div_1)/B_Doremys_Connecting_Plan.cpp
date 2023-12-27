/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-02 12:31:25
 *
 * Problem: B. Doremy's Connecting Plan
 * Contest: Codeforces - Codeforces Round 906 (Div. 1)
 * URL:     https://codeforces.com/problemset/problem/1889/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
 */
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr);
#define int long long
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
    int  n, c;
    cin >> n >> c;
    vector<PII> s;
    int sum = 0;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(i != 1)s.push_back({x - i * c, x});
        else sum += x;
    }
    sort(s.begin(), s.end(), [](PII a, PII b) {
        return a.fi > b.fi;
    });
    // for(auto [x, y] : s) {
    //     cout << x << ' ' << y << endl;
    // }
    for(auto [x, y] : s) {
        if(sum + x < 0) {
            cout << "No" << endl;
            return ;
        }
        sum += y;
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