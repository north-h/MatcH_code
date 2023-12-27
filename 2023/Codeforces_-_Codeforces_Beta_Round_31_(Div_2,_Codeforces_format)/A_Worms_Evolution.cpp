/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-10-04 16:17:34
 *
 * Problem: A. Worms Evolution
 * Contest: Codeforces - Codeforces Beta Round 31 (Div. 2, Codeforces format)
 * URL:     https://codeforces.com/contest/31/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    // sort(ALL(a));
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(a[i] + a[j] == a[k]) {
                    cout << k + 1 << ' ' << j + 1 << ' ' << i + 1 << endl;
                    return ;
                } else if(a[i] + a[k] == a[j]) {
                    cout << j + 1 << ' ' << k + 1 << ' ' << i + 1 << endl;
                    return ;
                } else if(a[k] + a[j] == a[i]) {
                    cout << i + 1 << ' ' << k + 1 << ' ' << j + 1 << endl;
                    return ;
                }
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}