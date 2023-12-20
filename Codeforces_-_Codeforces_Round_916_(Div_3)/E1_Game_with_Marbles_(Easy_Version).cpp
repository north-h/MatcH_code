/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-19 22:56:24
 *
 * Problem: E1. Game with Marbles (Easy Version)
 * Contest: Codeforces - Codeforces Round 916 (Div. 3)
 * URL:     https://codeforces.com/contest/1914/problem/E1
 * MemoryL: 256 MB
 * TimeL:   3500 ms
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

struct  S {
    int fi, se, id;
};

void solve() {
    int n;
    cin >> n;
    vector<S> a(n);
    vector<S>b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi;
        b[i].se = a[i].fi;
        a[i].id = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i].fi;
        a[i].se = b[i].fi;
        b[i].id = i;
    }
    sort(a.begin(), a.end(), [](S x, S y) {
        if(x.fi != y.fi)return x.fi > y.fi;
        return x.se > y.se;
    });
    // for(auto i : a)cout << i.fi << ' ' << i.se << endl;
    sort(b.begin(), b.end(), [](S x, S y) {
        if(x.fi != y.fi)return x.fi > y.fi;
        return x.se > y.se;
    });
    // for(auto i : b)cout << i.fi << ' ' << i.se << endl;
    ll ans = 0;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++) {
        if(vis[a[i].id])continue;
        ans += (a[i].fi - 1);
        vis[a[i].id] = 1;
        // debug1(a[i].fi);
        for(int j = 0; j < n; j++) {
            if(!vis[b[j].id] ) {
                vis[b[j].id] = 1;
                ans -= (b[j].fi - 1);
                // debug1(b[i].fi);
                break;
            }
        }
        // debug1(ans);
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