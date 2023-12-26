/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-26 13:30:36
 *
 * Problem: D. Pinkie Pie Eats Patty-cakes
 * Contest: Codeforces - SMU Autumn 2023 Round 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/494765/problem/D
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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    vector<PII> b;
    for(auto [x, y] : mp) {
        b.push_back({y, x});
    }
    sort(b.rbegin(), b.rend());
    // for(auto [x, y] : b)cout << x << ' ' << y << endl;
    vector<int> c;
    int sum = 0;
    while(c.size() < n) {
        for(int i = 0; i < b.size(); i++) {
            if(b[i].fi > 0) {
                c.push_back(b[i].se);
                b[i].fi--;
            }
        }
    }
    // debug1(c.size());
    int ans = INT_MAX;
    map<int, int> up;
    for(int i = 0; i < c.size(); i++) {
        if(!up.count(c[i]))up[c[i]] = i;
        else {
            ans = min(ans, max(0, i - up[c[i]] - 1));
            up[c[i]] = i;
        }
    }
    // for(auto i : c)cout << i << ' ';
    // cout << endl;
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}