/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-05 22:45:43
 *
 * Problem: D. Jumping Through Segments
 * Contest: Codeforces - Codeforces Round 913 (Div. 3)
 * URL:     https://codeforces.com/contest/1907/problem/D
 * MemoryL: 256 MB
 * TimeL:   5000 ms
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
    cin >> n;
    vector<PII> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    auto check = [&](int x)->bool{
        int l = -x;
        int r = x;
        for(int i = 0; i < n; i++) {
            if(l > a[i].se || r < a[i].fi )return false;
            else {
                l = max(l, a[i].fi) - x;
                r = min(r, a[i].se) + x;
            }
        }
        return true;
    };
    int l = 0, r = 1e10, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid))r = mid - 1, ans = mid;
        else ans = l = mid + 1;
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