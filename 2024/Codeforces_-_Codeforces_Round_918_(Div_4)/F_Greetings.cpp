/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2024-01-15 16:49:52
 *
 * Problem: F. Greetings
 * Contest: Codeforces - Codeforces Round 918 (Div. 4)
 * URL:     https://codeforces.com/contest/1915/problem/F
 * MemoryL: 256 MB
 * TimeL:   5000 ms
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
    vector<PII> a(n + 1);
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin() + 1, a.end(), [](PII x, PII y) {
        return x.fi < y.fi;
    });
    for(auto [x, y] : a)cout << x << ' ' << y << endl;
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        int l = i, r = n, ans = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            // debug2(a[i].se, a[mid].se);
            if(a[i].se >= a[mid].se)l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        debug1(ans);
        sum += ans - i;
    }
    cout << sum << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}