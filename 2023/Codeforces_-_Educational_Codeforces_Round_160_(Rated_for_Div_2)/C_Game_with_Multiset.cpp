/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-18 23:46:37
 *
 * Problem: C. Game with Multiset
 * Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
 * URL:     https://codeforces.com/contest/1913/problem/C
 * MemoryL: 256 MB
 * TimeL:   1500 ms
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
    int m;
    cin >> m;
    vector<int> a(30), b(30);
    b[0] = 1;
    for(int i = 1; i < 30; i++) {
        b[i] = b[i - 1] * 2;
    }
    while(m--) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            a[x]++;
        } else {
            for(int i = 29; i >= 0; i--) {
                int l = 0, r = a[i], ans = 0;
                while(l <= r) {
                    int mid = l + r >> 1;
                    if(mid * b[i] <= x) l = mid + 1, ans = mid;
                    else r = mid - 1;
                }
                x -= ans * b[i];
            }
            if(x == 0)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}