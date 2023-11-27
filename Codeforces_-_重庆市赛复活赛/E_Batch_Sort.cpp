/*
 * ===========================================================================
 * Author:  north_h
 * Time:    2023-11-25 16:30:29
 *
 * Problem: E. Batch Sort
 * Contest: Codeforces - 重庆市赛复活赛
 * URL:     https://codeforces.com/group/L9GOcnr1dm/contest/488622/problem/E
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
const int N = 25;
const int M = 1910;
const int MOD = 998244353;
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;

using namespace std;

int a[N][N];
int n, m;

void turn(int x, int y) {
    for(int i = 0; i < n; i++) {
        swap(a[i][x], a[i][y]);
    }
}

bool check() {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(a[i][j] != j + 1) {
                cnt++;
            }
        }
        if(cnt != 0 && cnt != 2)return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if(check()) {
        cout << "YES" << endl;
        return ;
    }
    for(int i = 0; i < m - 1; i++) {
        for(int j = i + 1; j < m; j++) {
            turn(i, j);
            if(check()) {
                cout << "YES" << endl;
                return ;
            }
            turn(i, j);
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    IOS;
    int h_h = 1;
    // cin >> h_h;
    while (h_h--)solve();
    return 0;
}