/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-26 11:12:21
 *
 * Problem: C. Matching Arrays
 * Contest: Codeforces - CodeTON Round 7 (Div. 1 + Div. 2, Rated, Prizes!)
 * URL:     https://codeforces.com/contest/1896/problem/C
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define ll long long
#define ld long double
#define ull unsigned long long
#define fi first
#define se second
#define PII pair<int,int>
#define PDD pair<double,double>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define ALL(a) a.begin(),a.end()
#define rALL(a) a.rbegin(),a.rend()
#define int128 __int128
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
#define PI acos(-1)
const int N = 10010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<PII> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].fi;
        b[i].se = i;
    }
    vector<int> ans(n);
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    // for(auto [x, y] : a)cout << x << ' ';
    // cout << endl;
    // for(auto [x, y] : b)cout << x << ' ';
    // cout << endl;
    for (int i = 0, j = x - 1; i < x; i++, j--) {
        // debug2(a[i].fi, b[j].fi);
        if (a[i].fi <= b[j].fi) {
            cout << "NO" << endl;
            return ;
        }
        ans[a[i].se] = b[j].fi;
    }
    for (int i = x, j = n - 1; i < n; i++, j--) {
        if (b[i].fi < a[j].fi) {
            cout << "NO" << endl;
            return ;
        }
        ans[a[j].se] = b[i].fi;
    }
    cout << "YES" << endl;
    for (auto i : ans)cout << i << ' ';
    cout << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}