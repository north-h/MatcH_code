/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-11-17 22:35:44
 *
 * Problem: C. Yarik and Array
 * Contest: Codeforces - Codeforces Round 909 (Div. 3)
 * URL:     https://codeforces.com/contest/1899/problem/C
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ==================================================================================
 */

#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
#define met_0(a) memset(a,0,sizeof a)
#define met_1(a) memset(a,-1,sizeof a)
#define met_x(a) memset(a,0x3f,sizeof a)
#define mpy(a, b) memcopy(a,sizeof b,b)
#define int long long
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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i] & 1)a[i] = 0;
        else a[i] = 1;
    }
    if(n == 1) {
        cout << b[1] << endl;
        return ;
    }
    int ans = INT_MIN;
    int res = b[1];
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i + 1]) {
            res += b[i + 1];
            ans = max(res, ans);
            if(res < 0)res = 0;
        } else {
            ans = max(res, ans);
            res = b[i + 1];
        }
    }
    ans = max(res, ans);
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}