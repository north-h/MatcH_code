/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-12-16 22:35:52
 *
 * Problem: B. Begginer's Zelda
 * Contest: Codeforces - Codeforces Round 915 (Div. 2)
 * URL:     https://codeforces.com/contest/1905/problem/B
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
    int n;
    cin >> n;
    vector<int> dg(n + 1);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dg[a]++;
        dg[b]++;
    }
    int ans = 0;
    int mx = *max_element(dg.begin() + 1, dg.end());
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        if(mx == dg[i] && ok) {
            ans += (dg[i] + 1) / 2;
            ok = false;
        } else {
            ans += (dg[i] - 1) / 2;
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