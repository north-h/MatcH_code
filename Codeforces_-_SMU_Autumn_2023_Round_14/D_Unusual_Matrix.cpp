/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-21 14:51:43
 *
 * Problem: D. Unusual Matrix
 * Contest: Codeforces - SMU Autumn 2023 Round 14
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/487840/problem/D
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

char a[N][N], b[N][N];
int n;

bool check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != b[i][j])return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    if(check()) {
        cout << "YES" << endl;
        return ;
    }
    for(int i = 0; i < n; i++) {
        if(a[0][i] != b[0][i]) {
            for(int j = 0; j < n; j++) {
                a[j][i] ^= 1;
            }
        }
    }
    for(int i = 1; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(a[i][j] != b[i][j]) {
                ok = false;
                break;
            }
        }
        if(!ok)for(int j = 0; j < n; j++)a[i][j] ^= 1;
    }
    if(check())cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    cin >> h_h;
    while (h_h--)solve();
    return 0;
}