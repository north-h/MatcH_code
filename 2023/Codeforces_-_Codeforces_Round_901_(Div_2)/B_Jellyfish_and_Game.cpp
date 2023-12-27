/*
 * ==================================================================================
 * Author:  north_h
 * Time:    2023-09-30 22:35:37
 *
 * Problem: B. Jellyfish and Game
 * Contest: Codeforces - Codeforces Round 901 (Div. 2)
 * URL:     https://codeforces.com/contest/1875/problem/B
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

int cnt = 0;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    int sa = 0;
    int sb = 0;
    for(auto &i : a)cin >> i, sa += i;
    for(auto &i : b)cin >> i, sb += i;

    sort(ALL(a));
    sort(ALL(b));
    if(k & 1) {
        if(a[0] < b[m - 1])swap(a[0], b[m - 1]);

    } else {
        if(a[0] >= b[m - 1]) {
            swap(a[n - 1], b[0]);
        } else {
            if(a[0] > b[0])swap(a[0], b[0]);
            if(a[n - 1] > b[m - 1])swap(a[n - 1], b[m - 1]);
        }
    }
    int sum = 0;
    for(auto i : a)sum += i;
    cout << sum << endl;
    // cout << accumulate(ALL(a), 0) << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}