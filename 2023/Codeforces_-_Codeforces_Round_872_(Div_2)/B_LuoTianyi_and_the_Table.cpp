/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-16 19:35:20
 *
 * Problem: B. LuoTianyi and the Table
 * Contest: Codeforces - Codeforces Round 872 (Div. 2)
 * URL:     https://codeforces.com/contest/1825/problem/B
 * MemoryL: 256 MB
 * TimeL:   1000 ms
 * ===========================================================================
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
#define PI acos(-1)
#define endl '\n'
#define lcm(x,y) x*y/__gcd(x,y)
#define debug1(a) cout<<#a<<'='<<a<<endl
#define debug2(a,b) cout<<#a<<'='<<a<<' '<<#b<<'='<<b<<endl
#define lf(x)   fixed << setprecision(x)
const int N = 1010;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    if(n > m)swap(n, m);
    for(int i = 0; i < n * m; i++)cin >> a[i];
    sort(ALL(a));
    int a1 = a[0], a2 = a[1], a3 = a[n * m - 1];
    int ans = (n - 1) * (a3 - a2) + (n * m - n) * (a3 - a1);
    a1 = a[0], a2 = a[n * m - 2], a3 = a[n * m - 1];
    ans = max(ans, (n - 1) * (a2 - a1) + (n * m - n) * (a3 - a1));
    cout << ans << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}