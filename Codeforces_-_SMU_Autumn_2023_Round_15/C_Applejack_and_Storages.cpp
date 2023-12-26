/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-12-26 13:30:32
 *
 * Problem: C. Applejack and Storages
 * Contest: Codeforces - SMU Autumn 2023 Round 15
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/494765/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ===========================================================================
 */
// #pragma GCC optimize("Ofast")
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
    int n;
    cin >> n;
    map<int, int> mp, up;
    vector<int> a(n + 1);
    int z = 0;
    int c = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]] % 4 == 0)z++;
        if(mp[a[i]] % 2 == 0)c++;
    }
    for(auto &[x, y] : mp)y %= 2;
    int q;
    cin >> q;
    while(q--) {
        char op;
        int x;
        cin >> op >> x;
        if(op == '-') {
            if(mp[x] <= 0) {
                if(c <= 0)mp[x] = 4, z--;
                else mp[x] = 2, c--;
            }
            mp[x]--;
        } else {
            mp[x]++;
            if(mp[x] >= 4)z += mp[x] / 4, c += mp[x] * 2, mp[x] %= 4;
            if(mp[x] >= 2)c += mp[x] / 2, mp[x] %= 2;
        }
        if(z >= 1  && c >= 4)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}