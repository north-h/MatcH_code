/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-04 11:56:01
 *
 * Problem: B. Vasya And The Matrix
 * Contest: Codeforces - SMU Autumn 2023 Trial 29
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/484045/problem/B
 * MemoryL: 256 MB
 * TimeL:   2000 ms
 * ===========================================================================
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
    int v1 = 0, v2 = 0;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        v1 ^= a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        v2 ^= b[i];
    }
    if(v1 != v2)cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << (a[1]^b[1]^v2) << ' ';
        for(int i = 2; i <= m; i++)cout << b[i] << ' ';
        cout << endl;
        for(int i = 2; i <= n; i++) {
            cout << a[i] << ' ';
            for(int j = 1; j < m; j++) {
                cout << 0 << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}