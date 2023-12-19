/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-19 22:56:24
 *
 * Problem: D. Three Activities
 * Contest: Codeforces - Codeforces Round 916 (Div. 3)
 * URL:     https://codeforces.com/contest/1914/problem/D
 * MemoryL: 256 MB
 * TimeL:   2000 ms
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
    vector<PII> a(n), b(n), c(n);
    vector<PII> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a.rbegin(), a.rend());
    for(int i = 0; i < 3; i++)d.push_back(a[i]);
    for(int i = 0; i < n; i++) {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(b.rbegin(), b.rend());
    for(int i = 0; i < 3; i++)d.push_back(b[i]);
    for(int i = 0; i < n; i++) {
        cin >> c[i].fi;
        c[i].se = i;
    }
    sort(c.rbegin(), c.rend());
    for(int i = 0; i < 3; i++)d.push_back(c[i]);
    int  ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 3; j < 6; j++) {
            for(int k = 6; k < 9; k++) {
                if(d[i].se != d[j].se && d[j].se != d[k].se && d[i].se != d[k].se) {
                    ans = max(ans, d[i].fi + d[j].fi + d[k].fi);
                }
            }
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